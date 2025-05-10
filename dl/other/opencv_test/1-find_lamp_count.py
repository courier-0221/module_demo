import cv2

jpg_path = r"/home/dear/下载/R2.jpeg"

def find_lamp_count():
    # 读取图片
    img = cv2.imread(jpg_path)

    # 将图片转换为灰度图像
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    cv2.imshow('image', gray)
    cv2.waitKey(0)

    # 进行二值化处理
    ret, thresh = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY)

    # 查找轮廓
    contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # 绘制轮廓
    cv2.drawContours(img, contours, -1, (0, 255, 0), 3)

    # 显示结果
    cv2.imshow('image', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

    # 输出灯光数量
    print('灯光数量：', len(contours))

if __name__ == "__main__":
    find_lamp_count()