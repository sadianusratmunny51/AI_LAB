 #include<bits/stdc++.h>
 using namespace std;
 vector<string>board;
 vector<vector<string>>ans;
 int cnt=0;
 int n;
 bool isSafe(int row, int col){
    int nrow=row;
    int ncol=col;
    for(int col=ncol;col>=0;col--){
        if(board[row][col]=='Q'){
            return false;
        }
    }
    row=nrow;
    col=ncol;
    while(row>=0&&col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    row=nrow;
    col=ncol;
    while(row<n&&col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;

    }
    return true;

 }
 void solve(int col){
    if(col==n){
      cnt++;
     // ans.push_back(board);
      return ;
    }
    for(int row=0;row<n;row++){
          if(board[row][col]=='.'){
             if(isSafe(row,col)){
                board[row][col]='Q';
                solve(col+1);
                board[row][col]='.';

             }
          }
    }
    return;
 }
 int32_t main(){
   // int n; 
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        s+='.';
    }
    for(int i=0;i<n;i++){
       board.push_back(s);
    }
    solve(0);
    cout<<cnt<<endl;
    // for(int i=0;i<ans.size();i++){
    //     for(int row=0;row<n;row++){
    //         cout<<ans[i][row]<<endl;
    //     }
    //     cout<<endl;
        
    // }


    return 0;
 }