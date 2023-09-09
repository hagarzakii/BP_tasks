int majorityElement(int* nums, int numsSize) {
    int majority = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            majority = nums[i];
            count = 1;
        } else if (majority == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == majority) {
            count++;
        }
    }

    if (count > numsSize / 2) {
        return majority;
    }
    return -1;
}