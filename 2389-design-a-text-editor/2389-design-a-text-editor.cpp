class TextEditor {
  vector<char> prev;
  stack<char> next;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
      for (char c: text) {
        prev.push_back(c);
      }
    }
    
    int deleteText(int k) {
      int count = 0;
      while (!prev.empty() && k > 0) {
        prev.pop_back();
        count++;
        k--;
      }
      return count;
    }
    
    string cursorLeft(int k) {
      while (!prev.empty() && k > 0) {
        next.push(prev.back());
        prev.pop_back();
        k--;
      }
      string res;
      for (int i = max(0, (int)prev.size() - 10); i < prev.size(); i++) {
        res += prev[i];
      }
      return res;
    }
    
    string cursorRight(int k) {
      while (!next.empty() && k > 0) {
        prev.push_back(next.top());
        next.pop();
        k--;
      }
      string res;
      for (int i = max(0, (int)prev.size() - 10); i < prev.size(); i++) {
        res += prev[i];
      }
      return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */