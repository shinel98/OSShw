#include "manager.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
        int input;
	int index = 0;
	int editnum;
	int delete;
	int deletenum;
	int count=0;
	Product *product[20];
	
	FILE *fp = fopen("./product.txt" , "r");
	if(fp == NULL) {
		printf("\n=>파일 없음\n");
	}
	else {
		printf("\n로딩 성공!\n");
		count = loadFile(product, fp);
		index += count;
		listProduct(product, index);
	}
        while(1) {
                int check = 0;
                input = printMenu();
                if(input == 0){
                        printf("방문해주셔서 감사합니다!\n");
                        break;
                }
                else if(input == 1) {
			#ifdef DEBUG 
				printf("=> debugging mode \n");
			#endif
			product[index] = (Product*)malloc(sizeof(Product));
                        check = createProduct(product[index++]);
                        if(check == 1){
                                printf("\n등록 성공!\n");
				count++;
			}
                }
                else if(input == 2) {
			#ifdef DEBUG 
				printf("=> debugging mode \n");
			#endif
			check = listProduct(product, index);
                        //check = readProduct(product);
                        if(check == 0)
                                printf("\n등록된 제품이 없습니다\n");
                }

                else if(input == 3) {
			#ifdef DEBUG 
				printf("=> debugging mode \n");
			#endif
			printf("몇번을 수정하시겠습니까?");
			scanf("%d" , &editnum);
		      	if(editnum > index || editnum < 0){
				printf("그런 번호는 없습니다.\n");
				continue;
			}	
                        check = updateProduct(product[editnum-1]);
                        if(check == 1){
                                printf("\n수정 완료!\n\n");
				listProduct(product, index);
			}
                }

                else if(input == 4) {
			#ifdef DEBUG 
				printf("=> debugging mode \n");
			#endif
			listProduct(product, index);
			printf("몇 번을 삭제하시겠습니까?\n");
			scanf("%d", &deletenum);
			if(deletenum > index || deletenum <= 0){
				printf("그런 번호는 없습니다.\n");
				continue;
		        }
                        printf("정말 삭제하시겠습니까? (네: 1/ 아니오: 2) >> ");
                        scanf("%d", &delete);
                        if(delete == 1){
                                check = deleteProduct(&product[deletenum-1]);
                                if(check)
                                        printf("삭제되었습니다.\n\n");
				listProduct(product, count);
                        }
                        else if(delete == 2){
                                printf("삭제가 취소되었습니다.\n");
                                continue;
                        }
                }
                else if(input == 5) {
                	int check = saveFile(product, index);
			if(check > 0){
				printf("저장됨!\n");
			}
			else 
				printf("저장 실패!\n");
		}
                else if(input == 6) {
               		searchProduct(product, index); 
		}
                else if(input == 7) {
                	reserveProduct(product, index);
		}
                else if(input == 8) {
                	searchByReserved(product, index);
		}
                else if(input == 9) {
			searchByChoice(product, index);
                }else{
			printf("옵션 중에 선택해주세요.\n");
			continue;
		}
        }
        return 0;
}
