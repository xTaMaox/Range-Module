class RangeModule {
public:
    RangeModule() {}
    map<int,int> _map; 
    
    void addRange(int left, int right) {
        operate(left, right - 1, true);
    }
    
    bool queryRange(int left, int right) {
        auto   it  = _map.lower_bound(right-1);
        return it != _map.end() && it->second <= left;
    }
    
    void removeRange(int left, int right) {
        operate(left, right - 1, false);
    }
    
    void operate(int l, int r, bool adding) {
        int   new_l = l, new_r = r;
        auto  it = _map.lower_bound(l - adding);
        
        while (it != _map.end() && it->second <= r + adding) {
            new_l = min(it->second, new_l);
            new_r = max(it->first, new_r);

            _map.erase(prev(++it));
        }
        
        if (adding) {
            _map[new_r] = new_l;
        } else {
            if (new_l < l) _map[l - 1] = new_l;
            if (new_r > r) _map[new_r] = r + 1;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */