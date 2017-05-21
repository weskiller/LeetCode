//https://leetcode.com/problems/lru-cache
class LRUCache {
private:
	unordered_map<int, int> MAP;
	list<int> LIST;
	int size;
public:
	LRUCache(int capacity) {
		size = capacity;
	}
	int get(int key) {
		list<int>::iterator pos = LIST.begin();
		while (pos != LIST.end()) {
			if (*pos == key) {
				LIST.erase(pos);
				LIST.push_front(key);
				return MAP[key];
			}
			pos++;
		}
		return -1;
	}

	void put(int key, int value) {
		if (MAP.find(key) == MAP.end()) {
			if (LIST.size() == size) {
				int val = LIST.back();
				LIST.pop_back();
				MAP.erase(val);
			}
			LIST.push_front(key);
		}
		else {
			for (list<int>::iterator x = LIST.begin(); x != LIST.end(); x++) {
				int val = *x;
				if (val == key) {
					LIST.erase(x);
					LIST.push_front(val);
					break;
				}
			}
		}
		MAP[key] = value;
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
