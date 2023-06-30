from adsys.proto.horizon_matrix import frame_v1_pb2
from mipilot.proto.perception import mono_frame_v2_pb2
from mipilot.proto.capture import image_group_info_pb2
from adsys.proto.capture import image_pb2
from mipilot.proto.perception import work_condition_pb2
from mipilot.proto.perception import camera_fail_pb2
from mipilot.proto.perception import parking_space_detection_pb2
from mipilot.proto.perception import free_space_pb2
from mipilot.proto.perception import obstacle_detection_pb2
from mipilot.proto.perception import parking_obstacle_detection_pb2
from mipilot.proto.perception import perception_to_state_machine_pb2
from mipilot.proto.localization import kinetic_localization_pb2
from mipilot.proto.perception import mono_frame_pb2
from mipilot.proto.perception import multi_localization_frames_pb2
from adsys.proto.common.trace2 import trace_pb2
import matplotlib.pyplot as plt
import google.protobuf.text_format as text_format
import argparse
from enum import Enum
import os
import glob
from multiprocessing import Pool
import sys
import numpy as np

gFileCount = 10
gFrameCount = 13

gKeyWordLists = [
    "PERCEPT/SurroundPostLaneUnit:Process",
    "PERCEPT/SurroundPostObstacleBboxUnit:Process",
    "PERCEPT/HandleImageData:HandleImageData",
    "PERCEPT/ParsingSampling:FindContoursEx",
    "PERCEPT/LaneDetectorParsing:PreprocessOneframe",
    "PERCEPT/VehicleDetector:PostProcessOneFrame"
]

class Channel(Enum):
    carame_group = 1            # "/sensors/camera/group" 
    mid_center_top_tele = 2     # "/perception/frame/v2/mid_center_top_tele" 
    hobot_inference = 3         # "/perception/surround/hobot_inference" 
    mid_center_top_wide = 4     # "/perception/frame/v2/mid_center_top_wide"
    front_pilot = 5             # "/perception/thumbnail/mid_center_top_wide/front_pilot"
    work_condition = 6          # "/perception/status/work_condition"
    camera_fail = 7             # "/perception/status/camera_fail"
    parking_spaces = 8          # "/perception/bev/parking_spaces"
    free_space = 9              # "/perception/bev/free_space"
    around_obstacles = 10       # "/perception/around/obstacles"
    parking_obstacles = 11      # "/perception/around/parking_obstacles"
    around_status = 12          # "/perception/around/status"
    kinetic_localization = 13   # "/localization/kinetic_localization"
    mono_frame = 14             # "/perception/mono/frame"
    surround_localization = 15  # "/perception/surround/localization"
    obstacle_detection = 16     # "/perception/surround/obstacles"
    rear_center_top_norm = 17   # "/perception/frame/v2/rear_center_top_norm

gChannelClassMap = {
    '-sensors-camera-group_info': Channel.carame_group,
    '-perception-surround-hobot_inference': Channel.hobot_inference,
    '-perception-frame-v2-mid_center_top_wide': Channel.mid_center_top_wide,
    '-perception-frame-v2-mid_center_top_tele': Channel.mid_center_top_tele,
    '-perception-thumbnail-mid_center_top_wide-front_pilot': Channel.mid_center_top_tele,
    '-perception-status-work_condition': Channel.work_condition,
    '-perception-status-camera_fail': Channel.camera_fail,
    '-perception-bev-parking_spaces': Channel.parking_spaces,
    '-perception-bev-free_space': Channel.free_space,
    '-perception-around-obstacles': Channel.around_obstacles,
    '-perception-around-parking_obstacles': Channel.parking_obstacles,
    '-perception-around-status': Channel.around_status,
    '-localization-kinetic_localization': Channel.kinetic_localization,
    '-perception-mono-frame': Channel.mono_frame,
    '-perception-surround-localization': Channel.surround_localization,
    '-perception-surround-obstacles': Channel.obstacle_detection,
    '-perception-frame-v2-rear_center_top_norm': Channel.rear_center_top_norm,
}

def GetAllFileNameFromDir(dirPath):
    # 列出目录下的所有文件名
    # import glob
    # pbTxtFilePathList = glob.glob(os.path.join(dirPath, "**", "*.pb.txt"), recursive=False)
    # timeList = [int(os.path.basename(pbTxtFilePath)[:-len(".pb.txt")]) for pbTxtFilePath in pbTxtFilePathList ]
    
    if False == os.path.exists(dirPath):
        # print(dirPath, os.path.exists(dirPath))
        return []

    all_files = []
    for filename in os.listdir(dirPath):
        file_path = os.path.join(dirPath, filename)
        if not os.path.isfile(file_path):
            continue
        if not filename.endswith('.pb.txt'):
            continue
        name_without_ext = filename.split('.')[0]
        if not name_without_ext.isdigit():
            continue
        all_files.append(int(name_without_ext))
    all_files = sorted(all_files)
    return all_files

def parseKeyWordFromChannelFile(dir_path, which_channel, all_files):
    results = []
    
    #sorted_files = sorted(all_files)[:gFileCount]
    sorted_files = sorted(all_files)
    for file_num in sorted_files:
        file_path = dir_path + '/' + str(file_num) + ".pb.txt"
        with open(file_path, "r") as f:
            contents = f.read()
        if which_channel == Channel.carame_group:
            new_imageinfo = image_group_info_pb2.ImageGroupInfo()
            text_format.Parse(contents, new_imageinfo)
            header_obj = new_imageinfo.header
        elif which_channel == Channel.hobot_inference:
            new_shuffle = frame_v1_pb2.FrameShuffle()
            text_format.Parse(contents, new_shuffle)
            header_obj = new_shuffle.header
        elif which_channel == Channel.mid_center_top_wide:
            new_monoframe = mono_frame_v2_pb2.MonoFrameV2()
            text_format.Parse(contents, new_monoframe)
            header_obj = new_monoframe.header
        elif which_channel == Channel.mid_center_top_tele:
            new_mid_center_top_tele = mono_frame_v2_pb2.MonoFrameV2()
            text_format.Parse(contents, new_mid_center_top_tele)
            header_obj = new_mid_center_top_tele.header
        elif which_channel == Channel.front_pilot:
            new_image = image_pb2.Image()
            text_format.Parse(contents, new_image)
            header_obj = new_image.header
        elif which_channel == Channel.work_condition:
            new_work_condition = work_condition_pb2.WorkCondition()
            text_format.Parse(contents, new_work_condition)
            header_obj = new_work_condition.header
        elif which_channel == Channel.camera_fail:
            new_camera_fail = camera_fail_pb2.CameraFail()
            text_format.Parse(contents, new_camera_fail)
            header_obj = new_camera_fail.header
        elif which_channel == Channel.parking_spaces:
            new_parking_space_detection = parking_space_detection_pb2.ParkingSpaceDetection()
            text_format.Parse(contents, new_parking_space_detection)
            header_obj = new_parking_space_detection.header
        elif which_channel == Channel.free_space:
            new_free_space = free_space_pb2.FreeSpace()
            text_format.Parse(contents, new_free_space)
            header_obj = new_free_space.header
        elif which_channel == Channel.around_obstacles or which_channel == Channel.obstacle_detection:
            new_obstacle_detection = obstacle_detection_pb2.ObstacleDetection()
            text_format.Parse(contents, new_obstacle_detection)
            header_obj = new_obstacle_detection.header
        elif which_channel == Channel.parking_obstacles:
            new_parking_obstacles = parking_obstacle_detection_pb2.ParkingObstacleDetection()
            text_format.Parse(contents, new_parking_obstacles)
            header_obj = new_parking_obstacles.header
        elif which_channel == Channel.around_status:
            new_around_status = perception_to_state_machine_pb2.PerceptionToStateMachine()
            text_format.Parse(contents, new_around_status)
            header_obj = new_around_status.header
        elif which_channel == Channel.kinetic_localization:
            new_kinetic_localization = kinetic_localization_pb2.KineticLocalization()
            text_format.Parse(contents, new_kinetic_localization)
            header_obj = new_kinetic_localization.header
        elif which_channel == Channel.mono_frame:
            new_mono_frame = mono_frame_pb2.MonoFrame()
            text_format.Parse(contents, new_mono_frame)
            header_obj = new_mono_frame.header
        elif which_channel == Channel.surround_localization:
            new_surround_localization = multi_localization_frames_pb2.MultiLocalizationFrames()
            text_format.Parse(contents, new_surround_localization)
            header_obj = new_surround_localization.header
        elif which_channel == Channel.rear_center_top_norm:
            new_monoframe = mono_frame_v2_pb2.MonoFrameV2()
            text_format.Parse(contents, new_monoframe)
            header_obj = new_monoframe.header

        else:
            print("not suppert")
        process_sequence_num = header_obj.process_sequence_num
        timestamp_ms = int(header_obj.timestamp_ns / 1000000)
        publish_timestamp_ms = int(header_obj.publish_timestamp_ns / 1000000)
        results.append((timestamp_ms, publish_timestamp_ms, process_sequence_num))

    return results

def prinf_cost(src, size, name):
    for i in range(0, size):
        print("%s cost[%f]ms" % (name, src[i][1] - src[i][0]), src[i][0])

def ParseSingleTrace2PbFile(inputFilePath):
    with open(inputFilePath, "r") as f:
        content = f.read()
    traceListObj = trace_pb2.TraceList()
    text_format.Parse(content, traceListObj)
    
    # Parse idx:label(str) dict
    labelIdxMap = dict()
    for string_idx in traceListObj.string_idx_list:
        labelIdxMap[string_idx.idx] = string_idx.str
        #print("key %d, value %s" % (string_idx.idx, labelIdxMap[string_idx.idx]))
    
    # Get Trace List
    traceList = []
    for trace in traceListObj.traces:
        start_ns = trace.start_ns
        end_ns = trace.end_ns
        process_frame_info = trace.process_frame_info
        process_seq = process_frame_info.process_sequence_num
        label = labelIdxMap[trace.category_idx] + ":" + labelIdxMap[trace.description_idx]
        #if 0 != process_seq:
        traceList.append((label, start_ns, end_ns, process_seq))
            #print((label, start_ns, end_ns, process_seq))
    
    return traceList

def FindMaxCostTimestamp(traceList):
    maxCost = 0
    maxCostStartTime = -1
    maxCostSeqNum = 0
    for i in range(len(traceList)):
        label,start_ns,end_ns,seq_num = traceList[i]
        #if label == "PERCEPT/LaneDetectorParsing:PreprocessOneframe":
        if label == "PERCEPT/SurroundMipilotApp:HobotFrontPilotUnit":
            costTime = end_ns-start_ns
            if costTime > maxCost:
                maxCost = costTime
                maxCostStartTime = start_ns
                maxCostSeqNum = seq_num

    print("maxCost=%d ms, maxCostStartTime=%d maxCostSeqNum=%d" % (maxCost/1e6, maxCostStartTime, maxCostSeqNum))

    return maxCostStartTime, maxCostSeqNum

def ParseTrace2InDir(inputPath):
    import pickle 
    traceBinFilePath = os.path.join(inputPath, "tracelist.bin")
    if os.path.exists(traceBinFilePath):
        print("Use existed trace bin file:", traceBinFilePath)
        with open(traceBinFilePath, "rb") as f:
            traceList = pickle.load(f)
            return traceList
    
    #desDir = os.path.join(inputPath, "-ados-apprt-trace2/")
    fileList = glob.glob(os.path.join(inputPath + "-ados-apprt-trace2", "**", "*.pb.txt"), recursive=True)
    traceList = []
    with Pool() as p:
        traceTable = p.map(ParseSingleTrace2PbFile, fileList)
    for traces in traceTable:
        traceList += traces
    
    with open(traceBinFilePath, "wb") as f:
        pickle.dump(traceList, f)
    return traceList

def getValue(printList, target):
    for item in printList:
        if item[0] == target:
            return item[1]
    return None

def filterNotInterestingLabel(label):
    if label == "-localization-kinetic_localization" or \
        label == "-perception-status-camera_fail" or \
        label == "-perception-status-work_condition" :
        return True
    else:
        return False

def drawLabelCostLineChart(printTable):
    labelLists = list()
    # 提取所有的label
    for printList in printTable:
        for label, _ in printList:
            if label not in labelLists:
                labelLists.append(label)
    #print(labelLists)

    xValue = [i for i in range(len(printTable))]
    yValueMap = {key: [] for key in labelLists}
    for i in range(len(labelLists)):
        for printList in printTable:
            ret = getValue(printList, labelLists[i])
            if ret != None:
                yValueMap[labelLists[i]].append(ret)
            else:
                yValueMap[labelLists[i]].append(0)
    
    index = 0
    # colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k']
    colors = ['b', 'g', 'r', 'c', 'm', 'y']
    for key, value in yValueMap.items():
        if key == "tigger_time":
            continue
        if filterNotInterestingLabel(key):
            continue
        if index < 6:
            plt.plot(xValue,value,linestyle='-',marker='o',color = colors[index%6],label=key)
        else:
            plt.plot(xValue,value,linestyle='--',marker='s',color = colors[index%6],label=key)
        
        index += 1
    plt.xlabel("num")#横坐标名字
    plt.ylabel("time")#纵坐标名字
    plt.legend(loc = "best")#图例
    plt.xticks(xValue)
    plt.yticks([i for i in range(200) if i % 10 == 0])
    plt.show()

    # print(xValue)
    # for key, value in yValueMap.items():
    #     print(key, value)


def drawHobotInferAndSeqNumLine(channelMsgListMap):
    inferSeqNumList = [ channel_sequence_num for _, _, channel_sequence_num in channelMsgListMap['-perception-surround-hobot_inference']]
    publishTimeList = [ publish_timestamp_ms for _, publish_timestamp_ms, _ in channelMsgListMap['-perception-surround-hobot_inference']]
    
    plt.plot(inferSeqNumList,publishTimeList,'o-',color = 'g',label="SEQ-PUBTIME")
    plt.xlabel("seq num")#横坐标名字
    plt.ylabel("publish time")#纵坐标名字
    plt.legend(loc = "best")#图例
    plt.xticks(inferSeqNumList, inferSeqNumList)
    plt.yticks(publishTimeList, publishTimeList)
    plt.show()

def drawHobotInferAndSeqNumBar(channelMsgListMap):
    inferSeqNumList = [ channel_sequence_num for _, _, channel_sequence_num in channelMsgListMap['-perception-surround-hobot_inference']]
    publishTimeList = [ publish_timestamp_ms for _, publish_timestamp_ms, _ in channelMsgListMap['-perception-surround-hobot_inference']]
    diffTimeList = []
    baseTime = publishTimeList[0]
    for node in publishTimeList[1:]:
        diffTimeList.append(node - baseTime)
        baseTime = node
    # print(publishTimeList)
    # print(diffTimeList)

    plt.bar(inferSeqNumList[1:], diffTimeList, color = "c",label='DIFF-TIME')
    plt.xlabel("seqnum")#横坐标名字
    plt.ylabel("difftime")#纵坐标名字
    plt.legend(loc = "best")#图例
    plt.xticks(inferSeqNumList[1:], inferSeqNumList[1:])
    plt.yticks(diffTimeList, diffTimeList)
    plt.show()

def drawPartCostBar(printTable, channelMsgListMap):
    seqNumList = [ channel_sequence_num for _, _, channel_sequence_num in channelMsgListMap['-perception-surround-hobot_inference']]

    xValue = [i for i in seqNumList]
    yValueMap = {key: [] for key in xValue}

    for i in range(len(printTable)):
        postProcessEndTime = [item[1] for item in printTable[i] if item[0] == "-perception-frame-v2-mid_center_top_wide"]
        postProcessBeginTime = [item[1] for item in printTable[i] if item[0] == "SurroundPostProcessApp:ProcessFrame:start"]
        hobotInferEndTime = [item[1] for item in printTable[i] if item[0] == "-perception-surround-hobot_inference"]
        hobotInferBeginTime = [item[1] for item in printTable[i] if item[0] == "SurroundMipilotApp:ProcessFrame:start"]
        if len(postProcessEndTime) and len(postProcessBeginTime):
            yValueMap[xValue[i]].append(("postTime", postProcessEndTime[0] - postProcessBeginTime[0], postProcessEndTime[0]))
        else:
            yValueMap[xValue[i]].append(("postTime", 0, 0))
        
        if len(postProcessBeginTime):
            yValueMap[xValue[i]].append(("waitTime", postProcessBeginTime[0] - hobotInferEndTime[0], hobotInferEndTime[0]))
        else:
            yValueMap[xValue[i]].append(("waitTime", 0, 0))
        
        yValueMap[xValue[i]].append(("inferTime", hobotInferEndTime[0] - hobotInferBeginTime[0], hobotInferEndTime[0]))

    for key, value in yValueMap.items():
        print("seqNum:%d (%s: cost %d ms, pubtime %d ms) (%s: cost %d ms, pubtime %d ms) (%s: cost %d ms, pubtime %d ms)" % \
              (key, value[0][0], value[0][1], value[0][2], \
               value[1][0], value[1][1], value[1][2], \
                value[2][0], value[2][1],value[2][2],))

    # plt.bar(inferSeqNumList[1:], diffTimeList, color = "c",label='DIFF-TIME')
    # plt.xlabel("seqnum")#横坐标名字
    # plt.ylabel("difftime")#纵坐标名字
    # plt.legend(loc = "best")#图例
    # plt.xticks(inferSeqNumList[1:], inferSeqNumList[1:])
    # plt.yticks(diffTimeList, diffTimeList)
    # plt.show()

def processFilePrintCost(inputPath):
    # 0 - Parse traces
    # traceList [(lable, start_time, end_time, seq_num)...]
    traceList = ParseTrace2InDir(inputPath)

    # 1 - Get max cost timestamp
    maxCostStartTime, _ = FindMaxCostTimestamp(traceList)
    # maxCostStartTime = 1687317910954174446
    beginTimestamp = maxCostStartTime - 33*gFrameCount*1000000
    endTimestamp = maxCostStartTime + 33*gFrameCount*1000000

    # 3 - Get all channel timestamp filename list
    # channelTimeMap {channel_name: [timestamp, ...]}
    channelTimeMap = dict()
    for channelName, cls in gChannelClassMap.items():
        channelDirPath = os.path.join(inputPath, channelName)
        channelTimeMap[channelName] = GetAllFileNameFromDir(channelDirPath)

    # 4 - filt insterest channel timestamp filename by beginTimestamp and endTimestamp
    filtedChannelTimeMap = dict()
    for channelName, timeList in channelTimeMap.items():
        filtedTimeList = [node for node in timeList if node > beginTimestamp and node < endTimestamp]
        #print("channelName=%s fileCount=%d" % (channelName, len(timeList)))
        filtedChannelTimeMap[channelName] = filtedTimeList

    # 5 - Get channel cost time Map
    channelMsgListMap = dict()
    for channelName, cls in gChannelClassMap.items():
        channelDirPath = os.path.join(inputPath, channelName)
        # if channelName == '-perception-surround-hobot_inference' or channelName == '-perception-frame-v2-mid_center_top_wide' :
        tsNPubtsSeqTupleList = parseKeyWordFromChannelFile(channelDirPath, cls, filtedChannelTimeMap[channelName])
        channelMsgListMap[channelName] = tsNPubtsSeqTupleList
    # print("minSeqNum %d, maxSeqNum %d" % (minSeqNum, maxSeqNum))

    
    # 2 - Filt traceList by seq
    #TODO：trace内容选取用seqnum，（max,min）只选推理和后处理两个模块
    inferSeqNumList = [ channel_sequence_num for _, _, channel_sequence_num in channelMsgListMap['-perception-surround-hobot_inference']]
    postSeqNumList = [ channel_sequence_num for _, _, channel_sequence_num in channelMsgListMap['-perception-frame-v2-mid_center_top_wide']]
    # print("inferSeqNumList", inferSeqNumList)
    # print("postSeqNumList", postSeqNumList)

    filtedTraceMap = {
        "SurroundMipilotApp:ProcessFrame:start": dict(),
        "SurroundPostProcessApp:ProcessFrame:start": dict()
    }
    for trace in traceList:
        label,start_ns,end_ns,seq_num = trace
        if "perception_surround_cameras_pilot_scheduled_high_30fps" in label:
            if seq_num in inferSeqNumList:
                filtedTraceMap["SurroundMipilotApp:ProcessFrame:start"][seq_num] = int(start_ns/1e6)
        elif "perception_surround_post_process" in label:
            if seq_num in postSeqNumList:
                filtedTraceMap["SurroundPostProcessApp:ProcessFrame:start"][seq_num] = int(start_ns/1e6)

    tsPubtsLabelSeqStrList = []
    oneLineList = []
    for i in range(0, len(channelMsgListMap["-sensors-camera-group_info"])):
        camera_timestamp_ms = channelMsgListMap["-sensors-camera-group_info"][i][0]
        for channelName, timeTupleList in channelMsgListMap.items():
            for timeTuple in timeTupleList:
                if camera_timestamp_ms == timeTuple[0]:
                    tsPubtsLabelSeqStrList.append("%13d"%timeTuple[0]+";"+"%13d"%timeTuple[1]+';'+channelName)
                    if channelName == '-perception-surround-hobot_inference':
                        tsPubtsLabelSeqStrList.append("%13d"%timeTuple[0]+";"+"%13d"%filtedTraceMap["SurroundMipilotApp:ProcessFrame:start"][timeTuple[2]]+';'+"SurroundMipilotApp:ProcessFrame:start")
                        oneLineList.append("%13d"%timeTuple[1]+';'+channelName)
                        oneLineList.append("%13d"%filtedTraceMap["SurroundMipilotApp:ProcessFrame:start"][timeTuple[2]]+';'+"SurroundMipilotApp:ProcessFrame:start")
                    elif channelName == '-perception-frame-v2-mid_center_top_wide':
                        tsPubtsLabelSeqStrList.append("%13d"%timeTuple[0]+";"+"%13d"%filtedTraceMap["SurroundPostProcessApp:ProcessFrame:start"][timeTuple[2]]+';'+"SurroundPostProcessApp:ProcessFrame:start")
                        oneLineList.append("%13d"%filtedTraceMap["SurroundPostProcessApp:ProcessFrame:start"][timeTuple[2]]+';'+"SurroundPostProcessApp:ProcessFrame:start")
                        oneLineList.append("%13d"%timeTuple[1]+';'+channelName)
                    break

    tsPubtsLabelSeqStrList = sorted(tsPubtsLabelSeqStrList)
    oneLineList = sorted(oneLineList)
    print("->".join(oneLineList))

    # printTable = []
    # curSensorTs = 0
    # for tsPubtsLabelSeqStr in tsPubtsLabelSeqStrList:
    #     ts,pubTs,label = tsPubtsLabelSeqStr.split(";")
    #     pubTs = int(pubTs)
    #     ts = int(ts)
    #     if curSensorTs != ts:
    #         printTable.append([])
    #         curSensorTs = ts
    #         printTable[-1].append(("tigger_time", ts))
    #     # printTable[-1].append((label, pubTs-curSensorTs))
    #     printTable[-1].append((label, pubTs))

    # for printList in printTable:
    #     print("->".join([label+"("+str(ts)+" ms)" for label,ts in printList]))

    # drawLabelCostLineChart(printTable)
    # drawPartCostBar(printTable, channelMsgListMap)
    # drawHobotInferAndSeqNumLine(channelMsgListMap)
    # drawHobotInferAndSeqNumBar(channelMsgListMap)


if __name__ == '__main__':
    HelpInfo = 'extract cost key.'
    parser = argparse.ArgumentParser(description=HelpInfo)
    parser.add_argument('-i', type=str, required=True, help='input file path')
    args = parser.parse_args()
    inputPath = args.i
    
    processFilePrintCost(inputPath)
    
    

    # ParseSingleTrace2PbFile("/mnt/work/record_parse/0621-1100/water-barrier/ParseRecordOut/-ados-apprt-trace2/1687317910933697129.pb.txt")
    

    





    