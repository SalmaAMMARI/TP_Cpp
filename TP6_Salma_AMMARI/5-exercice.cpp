#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>

// Structure to represent cache items
struct CacheItem {
    int key;
    std::shared_ptr<int> value;  // Using shared_ptr to manage value (key in this case)
};

// Structure to represent the LRU Cache itself
struct LRUCache {
    int capacity;
    std::list<std::shared_ptr<CacheItem>> cacheList; // List to store cache items
    std::unordered_map<int, std::list<std::shared_ptr<CacheItem>>::iterator> cacheMap; // Map for quick access to cache items

    // Function to access an element in the cache
    void access(int key) {
        // If the key is already in the cache
        if (cacheMap.find(key) != cacheMap.end()) {
            // Move the accessed item to the front of the list (recently used)
            cacheList.erase(cacheMap[key]);
        }

        // Create a shared_ptr for the new cache item
        auto newItem = std::make_shared<CacheItem>(CacheItem{key, std::make_shared<int>(key)});
        cacheList.push_front(newItem);
        cacheMap[key] = cacheList.begin();

        // If the cache exceeds its capacity, evict the least recently used item
        if (cacheList.size() > capacity) {
            // Evict the least recently used item (back of the list)
            auto evictedItem = cacheList.back();
            cacheList.pop_back();
            cacheMap.erase(evictedItem->key);

            // Use weak_ptr to avoid holding a strong reference to the evicted item
            std::weak_ptr<int> weakEvictedValue = evictedItem->value;
            if (auto lockedPtr = weakEvictedValue.lock()) {
                std::cout << "Eviction de la clé " << *lockedPtr << std::endl;
            }
        }
    }

    // Function to print the current state of the cache
    void printCache() {
        std::cout << "Cache actuel : ";
        for (auto& item : cacheList) {
            std::cout << *item->value << " ";  // Dereferencing the shared_ptr to get the value
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache cache = {4};  // Initialize cache with a capacity of 4

    // Simulating cache accesses
    cache.access(1);
    cache.access(2);
    cache.access(3);
    cache.access(1);  // Re-access key 1
    cache.access(4);  // Adding key 4
    cache.printCache();  // Print current cache state

    cache.access(5);  // Evicting key 2
    cache.printCache();  // Print current cache state after eviction

    return 0;
}
