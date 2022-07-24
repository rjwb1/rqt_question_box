#ifndef _SHARED_OBJECT_H_
#define _SHARED_OBJECT_H_
#include <memory>
#include <mutex>

namespace memory
{
class SharedMemory;

template<typename T>
class SharedObject {
public:

    friend class SharedMemory;

    SharedObject(std::string name = "");

    ~SharedObject() = default;

    //SharedObject(const SharedObject& that);

    //SharedObject<T>& operator= (const SharedObject& that);

    void setObject(const T &obj);

    T getObject();

private:

    std::shared_ptr<T> _obj;

    std::shared_ptr<std::mutex> _mutex;

    std::string _name;
};

template<typename T>
SharedObject<T>::SharedObject(std::string name):
        _obj(std::make_shared<T>()),
        _mutex(std::make_shared<std::mutex>()),
        _name(name) {

}

template<typename T>
void SharedObject<T>::setObject(const T &obj) {
    std::lock_guard<std::mutex> guard(*_mutex);

    *_obj = obj;
}

template<typename T>
T SharedObject<T>::getObject() {
    std::lock_guard<std::mutex> guard(*_mutex);

    return *_obj;
}
}

#endif
