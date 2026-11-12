int lowerBound(const vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size();

    while (s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] >= target) {
            e = mid;
        } else {
            s = mid + 1;
        }
    }
    return s;
}

// target 초과(>)가 처음 나타나는 인덱스 반환
int upperBound(const vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size();

    while (s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] > target) {
            e = mid;
        } else {
            s = mid + 1;
        }
    }
    return s;
}

int parametricSearchMax(const vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size();
    int ans = 0;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (check(mid, arr, target)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}