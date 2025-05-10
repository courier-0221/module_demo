#include <iostream>
#include <vector>

using namespace std;

// 定义了一个BBox结构体表示检测框，其中包含左上角和右下角的坐标、得分等信息。
// overlap函数用于计算两个检测框的重叠面积，nms函数实现了NMS算法，其中boxes是输入的所有检测框，threshold是重叠面积的阈值，result是输出的保留的检测框。
// 在nms函数中，我们首先将所有检测框按得分从高到低排序，然后依次选取得分最高的框作为输出，并将与该框重叠面积大于阈值的框删除，重复此过程直到所有框都被处理。

struct BBox {
    float x1, y1, x2, y2;
    float score;
};

float iou(const BBox& a, const BBox& b) {
    float area_a = (a.x2 - a.x1 + 1) * (a.y2 - a.y1 + 1);
    float area_b = (b.x2 - b.x1 + 1) * (b.y2 - b.y1 + 1);

    float x1 = max(a.x1, b.x1);
    float y1 = max(a.y1, b.y1);
    float x2 = min(a.x2, b.x2);
    float y2 = min(a.y2, b.y2);

    float intersection = max(0.0f, x2 - x1 + 1) * max(0.0f, y2 - y1 + 1);
    float iou = intersection / (area_a + area_b - intersection);

    return iou;
}

vector<BBox> nms(vector<BBox>& boxes, float threshold) {
    vector<BBox> result;

    while (boxes.size() > 0) {
        int max_idx = 0;
        for (int i = 1; i < boxes.size(); i++) {
            if (boxes[i].score > boxes[max_idx].score) {
                max_idx = i;
            }
        }

        BBox max_box = boxes[max_idx];
        result.push_back(max_box);
        boxes.erase(boxes.begin() + max_idx);

        for (int i = 0; i < boxes.size(); i++) {
            float overlap = iou(max_box, boxes[i]);
            if (overlap > threshold) {
                boxes.erase(boxes.begin() + i);
                // i--;
            }
        }
    }

    return result;
}

int main() {
    vector<BBox> boxes = {
        {10, 10, 50, 50, 0.9},
        {20, 20, 60, 60, 0.75},
        {30, 30, 70, 70, 0.8},
        {40, 40, 80, 80, 0.7},
        {50, 50, 90, 90, 0.6}
    };

    // float threshold = 0.5; //0.3;
    float threshold = 0.3;
    vector<BBox> result = nms(boxes, threshold);

    for (int i = 0; i < result.size(); i++) {
        cout << "Box " << i << ": (" << result[i].x1 << ", " << result[i].y1 << ", " << result[i].x2 << ", " << result[i].y2 << "), score = " << result[i].score << endl;
    }

    return 0;
}