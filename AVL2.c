#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
	int price;
	char name[25];
	struct Product* right;
	struct Product* left;
	int height;
};

// fungsi pembantu

int max(int a, int b) {
	return (a > b) ? a : b;
}

int getHeight(struct Product* p) { // cuma dipake untuk akses height jadi misal p tidak ada, dia tetap kasih height 0, dan bukan error
	if(p==NULL) return 0;
	return p->height;
}

int setHeight(struct Product* p) { // dari yang paling bawah, dia ditambah 1 1 sampai paling atas
	if(p==NULL) return 0;
	return 1 + max(getHeight(p->left), getHeight(p->right));
}

int getBalance(struct Product* p) { // dapet bf
	if(p==NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// pabrik

struct Product* newProduct(int price, char* name) {
	struct Product* product = (struct Product*)malloc(sizeof(struct Product));
	product->price = price;
	strcpy(product->name, name);
	product->left = product->right = NULL;
	product->height = 1;
	
	return product;
}

// rotate rotate

struct Product* leftRotate(struct Product* x) {
	struct Product* y = x->right;
	struct Product* z = y->left;
	
	x->right = z;
	y->left = x;
	
	x->height = setHeight(x);
	y->height = setHeight(y);
	
	return y;
}


struct Product* rightRotate(struct Product* x) {
	struct Product* y = x->left;
	struct Product* z = y->right;
	
	x->left = z;
	y->right = x;
	
	x->height = setHeight(x);
	y->height = setHeight(y);
	
	return y;
}

// insert

struct Product* insert(struct Product* p, int price, char* name) {
	if(p==NULL) return newProduct(price, name);
	
	if(price < p->price) {
		p->left = insert(p->left, price, name);
	} else if(price > p->price) {
		p->right = insert(p->right, price, name);
	} else {
		return p; // ga insert biar ga redundan
	}
	
	p->height = setHeight(p);
	
	int balance = getBalance(p);
	
	// RR
	if(balance < -1 && price > p->right->price) { // perlu ada 3 node
		return leftRotate(p);
	}
	
	// LL
	else if(balance > 1 && price < p->left->price) {
		return rightRotate(p);
	}
	
	// LR
	else if(balance > 1 && price > p->left->price) {
		p->left = leftRotate(p->left);
		return rightRotate(p);
	}
	
	// RL
	else if(balance < -1 && price < p->right->price) {
		p->right = rightRotate(p->right);
		return leftRotate(p);
	}
	
	return p;
}

//Inorder Traversal (Left - Root - Right)
//Postorder Traversal (Left - Right - Root)
//Preorder Traversal (Root - Left - Right)

void preOrder(struct Product* p) {
	if(p!=NULL) {
		printf("%d - %s - %d\n", p->price, p->name, p->height);
		preOrder(p->left);
		preOrder(p->right);
	}
}

// find

struct Product* findProduct(struct Product* root, int price){ // pppp
	if(root==NULL) return NULL;
	
	else if(price > root->price){
		return findProduct(root->right, price);
	}else if(price < root->price){
		return findProduct(root->left, price);
	}else{
		return root;
	}
}

// nyari predecessor

struct Product* getPredecessor(struct Product* root){ // fungsinya buat ngambil node yang paling kiri bawah
	struct Product* curr = root->left;
	while(curr->right){
		curr = curr->right;
	}
	
	return curr;
}

// DELETE -> Delete biasa kayak BST dan set new height trus di balancing!
struct Product* deleteProduct(struct Product* root, int price){
    if(root == NULL) return NULL;

    if(price < root->price){
        root->left = deleteProduct(root->left, price);
    }
    else if(price > root->price){
        root->right = deleteProduct(root->right, price);
    }
    else{
        // 0 child or 1 child
        if(root->left == NULL || root->right == NULL){
            struct Product* temp;

            if(root->left)
                temp = root->left;
            else
                temp = root->right;

            free(root);
            return temp;
        }

        // 2 children
        struct Product* pred = getPredecessor(root);

        root->price = pred->price;
        strcpy(root->name, pred->name);

        root->left = deleteProduct(root->left, pred->price);
    }

    // root may have become NULL
    if(root == NULL)
        return NULL;

    // update height
    root->height = setHeight(root);

    // rebalance
    int balance = getBalance(root);

    // LL
    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }

    // LR
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }

    // RL
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Product* updateProduct(struct Product* root, int oldPrice, int newPrice, char newName[]){
	struct Product* toUpdate = findProduct(root, oldPrice);
	
	if(toUpdate == NULL){
		printf("No data.");
	} else {
		root = deleteProduct(root, oldPrice);
		root = insert(root, newPrice, newName);
	}
	
	return root;
}

struct Product* deleteAll(struct Product* root){
	if(root==NULL) return NULL;
	
	root->left = deleteAll(root->left);
	root->right = deleteAll(root->right);
	free(root);
	
	return NULL;
}

int main() {
    printf("Start\n");

    struct Product* p = NULL;


    p = insert(p, 77, "Laptop");
    p = insert(p, 48, "Keyboard");
    p = insert(p, 43, "Mouse");
    p = insert(p, 13, "Cable");
    p = insert(p, 37, "Disk");

    p = updateProduct(p, 77, 65, "LAPTOP");
    preOrder(p);

    return 0;
}