class Solution {
public:
    string simplifyPath(string path) {
        if (path.back() != '/') path += '/';
        string res, name;
        res.reserve(path.size());

        for (auto c : path)
        {
            if (c != '/') name += c;
            else
            {
                if (name == "..")
                {
                    while (!res.empty() && res.back() != '/') res.pop_back();
                    if (!res.empty()) res.pop_back();
                }
                else if (name != "." && name != "")
                {
                    res += '/' + name;
                }
                name.clear();
            }
        }
        if (res.empty()) return "/";
        return res;
    }
};
