class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        begin = vec2d.begin();
        end = vec2d.end();
        if (begin != end) iter = (*begin).begin();
    }

    int next() {
        hasNext();
        return *(iter++);
    }

    bool hasNext() {
        while(begin != end && (iter == (*begin).end())) {
            begin++;
            iter = (*begin).begin();
        }
        return begin != end;
    }

private:
    vector<vector<int>>::iterator begin, end;
    vector<int>::iterator iter;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */