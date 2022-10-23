//lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素
//找到第一个a[index]>=target
auto it = lower_bound(row.begin(), row.end(), target);
if (it != row.end() && *it == target) {
    return true;
}

//upper_bound() 在指定范围内查找大于目标值的第一个元素
int *p = upper_bound(a, a + 5, 3);

