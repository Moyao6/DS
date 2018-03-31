#include <iostream>
#include <algorithm>
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
    friend std::ostream& operator << (std::ostream&os, sList<T>&sl){//输出
        for(int i = 0; i < sl.size(); i++){
            if(i != 0) os << " ";
            os << sl[i];
        }
        return os;
    }
};

template<class T>
sList<T>::sList(int ml){
    length = 0;
    maxLength = ml;
    elems = new T(ml);
}

template<class T>
sList<T>::~sList(){
    if(elems)delete [] elems;
    elems = NULL;
}

template<class T>
bool sList<T>:: insert(int pos, T val){
    if(length == maxLength)return false;
    for(int i = length; i > pos; i--)
        elems[i] = elems[i-1];
    length++;
    elems[pos] = val;
    return true;
}

template<class T>
bool sList<T>:: push(T value) {
    if(length == maxLength)return false;
    elems[length] = value;
    length ++;
    return true;
}

template<class T>
bool sList<T>:: remove(int pos){
    if(isempty())return false;
    if(length <= pos)return false;
    for(int i = pos; i < length - 1; i++){
        elems[i] = elems[i + 1];
    }
    length --;
    return true;
}

template<class T>
inline bool sList<T>:: isempty(){return size() == 0;}

template<class T>
inline int sList<T>:: size(){return length;}

template<class T>
inline bool sList<T>:: change(int pos ,T val){
    if (pos >= size())     return false;
    elems[pos]=val;
    return true;
}

template<class T>
int sList<T>:: find(T val){
    for(int i = 0; i < size(); i++){
        if(val == elems[i])
            return i;
    }
    return -1;
}

template<class T>
T sList<T>:: operator [] (const int pos)const{
    return elems[pos];
}

template<class T>
void sList<T>:: sort(bool mode){
    if(mode){
        std::sort(elems, elems+length);
    }else{
        std::sort(elems, elems + length, std::greater<T>());
    }
}

