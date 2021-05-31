class SubrectangleQueries {
    vector <vector <int> > rect,changes;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        changes.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        for (int i=changes.size()-1;i>=0;i--){
            if (
                row>=changes[i][0] &&
                row<=changes[i][2] &&
                col>=changes[i][1] &&
                col<=changes[i][3]
               )
            {
                return changes[i][4];
            }
        }
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */