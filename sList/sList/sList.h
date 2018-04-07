//
//  sList.h
//  sList
//
//  Created by 邵伟 on 2018/4/7.
//  Copyright © 2018年 Weis. All rights reserved.
//
#ifndef sList_h
#define sList_h
template<class T>
class sList{
private:
    int length, maxLength;//长度、最大长度
    T* elems;//头指针
public:
    sList(int = 10);
    ~sList();//析构
    bool insert(int, T);//插入
    bool push(T);//尾部插入
    bool remove(int);//删除
    inline bool isempty();//是否为空
    inline int size();//顺序表大小
    inline bool change(int ,T);//改变元素值
    int find(T);//查找返回下标
    T operator [] (const int) const;//访问元素(不可改变值)
    void sort(bool = 1);//排序
};
#endif /* sList_h */
