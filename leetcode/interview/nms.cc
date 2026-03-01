#include <iostream>
#include <vector>
using namespace std;

/*
|left1,top1
|   left2,top2
|               right1,bottom1
|                   right2,bottom2
___________________
*/

struct dect {
    int left;
    int top;
    int right;
    int bottom;
};


class solution {
public:
    vector<dect> process(vector<dect>& objs, float thr=0.7) {
        vector<bool> used(objs.size(), false);
        vector<dect> ret;

        for (int i = 0; i < objs.size(); i++) {
            for (int j = i + 1; j < objs.size(); j++) {
                if (thr < iou(objs[i], objs[j])) {
                    used[j] = true;
                } 
            }
        }

        for (int i = 0; i < objs.size(); i++) {
            if (used[i]) {
                ret.push_back(objs[i]);
            }
        }
        return ret;
    }

    float iou(const dect &obj1, const dect &obj2) {
        int mother = ((obj1.right - obj1.left) * (obj1.top - obj1.bottom)) + \
            ((obj2.right - obj2.left) * (obj2.top - obj2.bottom));

        int left = max(obj1.left, obj2.left);
        int top = max(obj1.top, obj2.top);
        int right = min(obj1.right, obj2.right);
        int bottom = min(obj1.bottom, obj2.bottom);

        int chile = (right - left) * (top - bottom);

        return chile / (mother - chile);
    }

};


int main(void) {
    
    return 0;
}