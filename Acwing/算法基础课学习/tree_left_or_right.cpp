int id;
    bool flag = false;
    void dfs(TreeNode* root){
        if(!root)return ;
        if(root -> val == id){
            flag = true;
            return;
        }
        if(root -> left){
            if(root -> left -> val == id){
                flag = true;
                return;
            }
        }
        if(root -> right){
            if(root -> right -> val == id){
                flag = true;
                return;
            }
        }
        dfs(root -> left);
        dfs(root -> right);
    }

用法： dfs(root ->left)判断是否在左边
