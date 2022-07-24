#ifndef _SHARED_MEMORY_H_
#define _SHARED_MEMORY_H_
#include <memory>
#include <map>
#include <boost/any.hpp>
#include <rqt_question_box/shared_memory/SharedObject.h>

namespace memory
{
class SharedMemory
{
public:

    typedef std::shared_ptr<SharedMemory> Ptr;

    SharedMemory(const SharedMemory &) = delete;

    void operator=(const SharedMemory &) = delete;

    static Ptr getInstance();

    template<typename T>
    SharedObject <T> getSharedObject(const std::string &name);


private:

    SharedMemory() = default;

    std::mutex _mutex;

    std::map<std::string, boost::any> _shared_objects;
};

inline SharedMemory::Ptr SharedMemory::getInstance()
{
    static SharedMemory::Ptr instance{new SharedMemory};

    return instance;
}

template<typename T>
inline SharedObject <T> SharedMemory::getSharedObject(const std::string &name) {
    std::lock_guard<std::mutex> guard(_mutex);

    if (_shared_objects.count(name) == 0) {

        _shared_objects[name] = boost::any(SharedObject<T>(name));

    }

    SharedObject <T> *obj = boost::any_cast<SharedObject < T> > (&(_shared_objects.at(name)));

    if (!obj) {
        throw std::runtime_error("Could not create shared object...");
    }

    return *obj;

}
}

#endif
