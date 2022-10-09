#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n; //数组length
int a[100000];

//1.普通二分：查找数存不存在或者随便找一个
int binarySearchOne(int target){
    int l=0,r=n-1,m;
    while(l<=r){   //设定为l<=r,当跳出while后必然是l=r+1
        m=(l+r)/2;
        if( a[m]<target ){
            l=m+1;
        }
        else if( a[m]>target ){
            r=m-1;
        }
        else return m;
    }
    return -1;
}


//2.第一个等于target的数
int firstEqual(int target){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        //如果此时m是第一个等于target的数，r=m-1后不会再变了，等到l>r时就是第一个符合要求的元素
        //可知a[m-1]<target,r=m-1,有因为跳出while循环之后l=r+1=m,因此结果正确
        if(a[m]>=target)
            r=m-1;
        else
            l=m+1;
    }
    //元素也可能不存在，需要先判断越界和符合情况
    //l>=n会在target大于数组中所有数时出现
    if(l<n && a[l]==target)
        return l;
    return -1;
}


// 3.找第一个大于target的数
int binarySearchFirstMore(int target){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        if( a[m]>target )
            r=m-1;
        else
            l=m+1;
    }

    // if(l>=n) return -1; else return l;
    return l>=n?-1:l;
}

// 4.找第一个大于等于目标值的数
// 其主体和“第一个等于target的数”,只是最后的返回不同 边界条件都是a[m]>=target
int binarySearchFirstMoreEquals(int target){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        if( a[m]>=target ) //边界条件，保证迭代到最后，r是最后一个不满足边界条件的元素，因此r+1必然是第一个满足的
            r=m-1;
        else
            l=m+1;
    }
    return l>=n?-1:l;
}

//最后一个  返回r
// 5.找最后一个等于target的数
int lastEqual(int target){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        if(a[m]<=target) //边界条件，让l在迭代后成为第一个不满足边界条件的数字
        //则r=l-1必然是最后一个满足的
            l=m+1;
        else 
            r=m-1;
    }   
    if(r>=0 && a[r]==target)
        return r;
    return -1;
}

// 6.找最后一个小于target的数
int binarySearchLastLess(int target){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        if( a[m]<target )
            l=m+1;
        else
            r=m-1;
    }
    //如果r<0的话也是-1，不用判断了
    //return r<0?-1:r;
    return r;
}

// 7.找最后一个小于等于target的数
int binarySearchLastLessEquals(int target){
    int l=0,r=n-1,m;
    while (l<=r){
        m=(l+r)/2;
        if( a[m]<=target )
            l=m+1;
        else
            r=m-1;
    }
    //如果r<0的话也是-1，不用判断了
    //return r<0?-1:r;
    return r;
}

//用l+(r-l)/2替代(l+r)/2防止溢出

/*
9.总结

(1)第一个...的情况最后返回的都是l，主要通过判断r的移动来操作

寻找第一个等于target的，判断条件是if(a[m]>=target) r=m-1；最后判断l合法性以及是否存在；
寻找第一个大于等于target的，判断条件也是if(a[m]>=target) r=m-1；
寻找第一个大于target的，判断条件是if(a[m]>=target) r=m-1；

(2)最后一个...的情况返回的都是r，主要通过判断l的移动来操作

寻找最后一个等于target的，判断条件是if(a[m]<=target) l=m+1;最后判断r合法性以及是否存在；
寻找最后一个小于等于target的，判断条件也是if(a[m]<=target) l=m+1；
寻找最后一个小于target的，判断条件是if(a[m]<target) l=m+1；

*/

int main(){
    return 0;
}