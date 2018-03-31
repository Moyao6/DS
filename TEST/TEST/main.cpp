#include <iostream>
#include <algorithm>
template<class T>
class sList{
private:
    int length;
    int maxLength;
    T* elems;
public:
    sList(int = 10);
    ~sList();
    bool insert(int, T);
    bool push(T);
    bool pop(int);
    inline bool isempty();
    inline int size(){return length;}
    inline bool change(int pos ,T val){
        if (pos >= size())     return false;
        elems[pos]=val;
        return true;
    }
    int find(T val){
        for(int i = 0; i < size(); i++){
            if(val == elems[i])
                return i;
        }
        return -1;
    }
    T operator [] (const int pos)const{
        return elems[pos];
    }
    void sort(bool mode = 1){
        if(mode){
            std::sort(elems, elems+length);
        }else{
            std::sort(elems, elems + length, std::greater<T>());
        }
    }
    friend std::ostream& operator << (std::ostream& os, sList<T>& sl){
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
bool sList<T>:: pop(int pos){
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

