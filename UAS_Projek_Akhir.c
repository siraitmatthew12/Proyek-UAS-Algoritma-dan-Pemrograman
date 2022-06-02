#include<stdlib.h>
#include <stdio.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void binaryTree();
typedef struct Mahasiswa{
  char nama[100];
  int umur;
  char jenisKelamin;
  char Jurusan[100];
} Mahasiswa;

struct node{
        Mahasiswa dataMahasiswaNode;
        struct node *next;
};
struct node *start=NULL;
int main(){
        int choice;
        int position;
        while(1){
        printf("\nPetunjuk Panduan Penggunaan Program:\n");
    	printf("Program ini merupakan sebuah simulasi databse mahasiswa\n");
	    printf("Terdapat 8 buah pilihan yakni Create (opsi 1), Read (opsi 2), Update (opsi 3), Delete (opsi 4), Binary Tree (opsi 5), dan Akhiri program (opsi 8)\n");
	    printf("1. Create (berfungsi untuk menambahkan data mahasiswa)\n");
	    printf("2. Read (berfungsi untuk menampilkan daftar yang tertera dalam database)\n");
	    printf("3. Update (berfungsi untuk mengubah daftar yang tertera dengan urutan tertentu)\n");
	    printf("4. Delete (berfungsi untuk menghilangkan daftar yang tertera dengan urutan tertentu)\n");
	    printf("5) Penggunaan Binary Tree (Sort dan Search)\n");
	    printf("6) End Program\n");
				printf("Masukkan pilihan Anda!\n>> ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                         case 3:
                                         printf("\nSilahkan Masukkan Posisi Yang Hendak Diubah");
                                         scanf("%d", &position);
										 delete_pos(position);
										 if(position==0){
										 	insert_pos(0);
										 }else{
										 	insert_pos(position-1);
										 }
                                         break;
                         case 4:
                                        delete_pos(position);
                                         break;
                         case 5:
                         				binaryTree();
                         				break;
                         case 6:
                                         exit(0);
                                         break;
                             
                        default:
                                        printf("\n Pilihan Tidak Tersedia\n");
                                        break;
                }
        }
        return 0;
}
void create(){
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
          printf("Silahkan Masukkan Nama Mahasiswa Baru: ");
          getchar();
      	scanf("%[^\n]", &temp->dataMahasiswaNode.nama);
      	
        printf("\nSilahkan Masukkan Umur Mahasiswa Baru: ");
        scanf("%d",&temp->dataMahasiswaNode.umur);
        printf("\nSilahkan Masukkan Jenis Kelamin Mahasiswa Baru: ");
        getchar();
        scanf("%c",&temp->dataMahasiswaNode.jenisKelamin);
    
        printf("Silahkan Masukkan Jurusan Mahasiswa Baru: ");
         getchar();
      	scanf("%[^\n]", &temp->dataMahasiswaNode.Jurusan);

        temp->next=NULL;
        if(start==NULL){
                start=temp;
        }
        else{
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display(){
	int counter=0;
	printf("\n\n=========================\n");
    printf("Database Mahasiswa:\n");
    printf("=========================\n");
        struct node *ptr;
        if(start==NULL)
        {
               printf("=========================\n");
			    printf("Mohon Maaf Database Masih Kosong");
			    printf("=========================\n");
                return;
        }
        else
        {
                ptr=start;
                while(ptr!=NULL)
                {
                        
						
				        printf("\nData ke-%d\n",counter+1);
				        printf("=========================\n");
						printf("\nNama            :%s",ptr->dataMahasiswaNode.nama );
                        printf("\nUmur            :%d",ptr->dataMahasiswaNode.umur );
                        printf("\nJenis Kelamin   :%c",ptr->dataMahasiswaNode.jenisKelamin);
                        printf("\nJurusan         :%s",ptr->dataMahasiswaNode.Jurusan );
                       ptr=ptr->next ;
      					counter+=1;
                }
        }
}


 void insert_pos(int pos){
         struct node *ptr,*temp;
         int i;
         temp=(struct node *)malloc(sizeof(struct node));
         if(temp==NULL)
         {
                 printf("nOut of Memory Space:n");
                 return;
         }
         printf("Silahkan Masukkan Nama Mahasiswa Baru: ");
          getchar();
      	scanf("%[^\n]", &temp->dataMahasiswaNode.nama);
      	
        printf("\nSilahkan Masukkan Umur Mahasiswa Baru: ");
        scanf("%d",&temp->dataMahasiswaNode.umur);
        printf("\nSilahkan Masukkan Jenis Kelamin Mahasiswa Baru: ");
        getchar();
        scanf("%c",&temp->dataMahasiswaNode.jenisKelamin);
    
        printf("Silahkan Masukkan Jurusan Mahasiswa Baru: ");
         getchar();
      	scanf("%[^\n]", &temp->dataMahasiswaNode.Jurusan);
         temp->next=NULL;
         if(pos==0){
                 temp->next=start;
                 start=temp;
         }
         else
         {
                 for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                         if(ptr==NULL)
                         {
                                 printf("\nMohon Maaf Urutan Tidak Ditemukan\n");
                                 return;
                         }
                 }
                 temp->next =ptr->next ;
                 ptr->next=temp;
         }
 }
 
void delete_pos(int pos){
        int i;
        struct node *temp,*ptr;
        if(start==NULL){
            printf("\n List Kosong\n");
            exit(0);
        }
        else{
                if(pos==0){
                        ptr=start;
                        start=start->next ;
                        printf("Sukses Menghapus Data Mahasiswa dalam urutan:%d", pos);
                        printf("\nNama            :%s",ptr->dataMahasiswaNode.nama );
                        printf("\nUmur            :%d",ptr->dataMahasiswaNode.umur );
                        printf("\nJenis Kelamin   :%c",ptr->dataMahasiswaNode.jenisKelamin);
                        printf("\nJurusan         :%s",ptr->dataMahasiswaNode.Jurusan );
                        free(ptr);
                }
                else{
                         ptr=start;
                         for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                 if(ptr==NULL){
                                         printf("\Element tidak ditemukan:\n");
                                         return;
                                 }
                         }
                         temp->next =ptr->next ;
                         printf("Sukses Menghapus Data Mahasiswa dalam urutan:%d", pos);
                        printf("\nNama            :%s",ptr->dataMahasiswaNode.nama );
                        printf("\nUmur            :%d",ptr->dataMahasiswaNode.umur );
                        printf("\nJenis Kelamin   :%c",ptr->dataMahasiswaNode.jenisKelamin);
                        printf("\nJurusan         :%s",ptr->dataMahasiswaNode.Jurusan );
                         free(ptr);
                 }
         }
 }
 
 
#include<stdlib.h>
#include<stdio.h>

struct tahunLulusMahasiswa {
int tahunLulus;
struct tahunLulusMahasiswa * right, * left;
};
typedef struct tahunLulusMahasiswa node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->tahunLulus = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->tahunLulus)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->tahunLulus)
    {
        insert(&(*tree)->right, val);
    }
}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->tahunLulus);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->tahunLulus);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->tahunLulus);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->tahunLulus)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->tahunLulus)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->tahunLulus)
    {
        return *tree;
    }
}

void binaryTree()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    
    int i, jumlahData, dataTahunLulus, pilihan, susunan;
    
        do{
    	printf("\nPetunjuk Panduan Penggunaan Program:\n");
    	printf("Program ini merupakan sebuah simulasi databse mahasiswa\n");
	    printf("1. Terdapat 5 buah pilihan yakni \nCreate (opsi 1), \nRead (opsi 2), \nSearch (opsi 3), \nSort (opsi 4), \nEnd (opsi 5)\n");
//    	printf("\n%d\n", urutan);
    	printf("\nSilahkan Masukkan Pilihan Anda (1-5)\n>> ");
	    scanf("%d",&pilihan);
	    switch(pilihan){
		case 1:
	    	printf("Masukkan data tahunLulus!\n>> ");
	    	scanf("%d", &dataTahunLulus);
	    	insert(&root, dataTahunLulus);
			break;
		case 2:
		    printf("Ini datanya\n");
		    print_inorder(root);
			break;
		case 3:
			/* Search node into tree */
			printf("Masukkan data yang hendak dicari!\n>> ");
			scanf("%d", &dataTahunLulus);
		    tmp = search(&root, dataTahunLulus);
		    if (tmp)
		    {
		        printf("Node yang ditemukan = %d\n", tmp->tahunLulus);
		    }
		    else
		    {
		        printf("Data tahunLulus tidak ditemukan.\n");
		    }
			break;
		case 4:
			printf("Ingin sort dalam urutan apa?\n1. untuk preorder\n2. untuk inorder\n3. untuk postorder\n>> ");
			scanf("%d", &susunan);
			switch(susunan){
			    /* Printing nodes of tree */
			    case 1:
				    printf("Pre Order Display\n");
				    print_preorder(root);
			    break;
				case 2:
				    printf("In Order Display\n");
				    print_inorder(root);
			    break;
			    case 3:
				    printf("Post Order Display\n");
				    print_postorder(root);
			    break;
			}
			break;
		case 5:
			pilihan = 8;
			break;
		default:
			printf("Maaf pilihan anda salah, silakan input kembali");
			break;
		}		
	}while(pilihan!=8);
    
    /* Deleting all nodes of tree */
    deltree(root);
}
