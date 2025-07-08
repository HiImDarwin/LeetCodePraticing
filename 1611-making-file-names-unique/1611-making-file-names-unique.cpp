class Solution {
public:
    // vector<string> getFolderNames(vector<string>& names) {
    //   int n = names.size();
    //   unordered_map<string,int> mp;
    //   vector<string> res;

    //   for(string name : names) {
    //     size_t pos = name.find('(');
    //     bool hasbracket = false;
    //     int bracketVal;
    //     string trueName;
    //     if(pos != string::npos) {
    //       int lastPos = pos;
    //       while(isdigit(name[lastPos])){
    //         lastPos++;
    //       }
    //       if (name[lastPos] == ')') {
    //         hasbracket = true;
    //         bracketVal = stoi(name.substr(pos+1,lastPos - pos -1));
    //         trueName = name.substr(0,pos);
    //       }
    //     }

    //     if(hasbracket) {
    //       if(mp.count(trueName) && mp[trueName] > bracketVal) {
    //         bracketVal = mp[trueName]+1;
    //         trueName = trueName + "(" + to_string(bracketVal) + ")";
    //       } 
    //       pushName(mp,trueName,res);
    //     } else {
    //       if(mp.count(name)) {
    //         string folderName = name + "(" + to_string(mp[name]) + ")";
    //         while(mp.count(folderName)) {
    //           mp[name]++;
    //           folderName = name + "(" + to_string(mp[name]) + ")";
    //         }
    //         pushName(mp, folderName, res);
    //       } else {
    //         pushName(mp, name, res);
    //       }
    //     } 
    //   }
    //   return res;
    // }

    // void pushName(unordered_map<string,int> &mp, string name,vector<string> &res) {
    //   if(mp.count(name)) {
    //     string ne = name + "(" + to_string(mp[name]) + ")";
    //     res.push_back(ne);
    //   } else {
    //      res.push_back(name);
    //   }
    //   mp[name]++;
    // }
vector<string> getFolderNames(vector<string>& names) 
    {
        unordered_map<string,int>Map;
        vector<string>rets;
        
        for (auto name: names)
        {
            if (Map.find(name)!=Map.end())            
            {                
                while (Map.find(name + "(" + to_string(Map[name]) + ")")!=Map.end())
                    Map[name] += 1;
                string new_name = name + "(" + to_string(Map[name]) + ")";                
                rets.push_back(new_name);                
                Map[name]+=1;
                Map[new_name] = 1;
            }
            else            
            {
                rets.push_back(name);                
                Map[name] = 1;
            }
                
        }
        return rets;
        
    }
};

/*

[sta, sta(2), sta(3), sta, sta(2)]

cornor case
* name has round brackets
  * inside round brackets aren't digit > take as unique name
  * inside round brackets are digit 
    > check for the name without digit
      > digit lower than name
      > digit bigger than name
* name dont has round brackets
  > check for the name with digit


Question 
1. can the name be empty?

*/