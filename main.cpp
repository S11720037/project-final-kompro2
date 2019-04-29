#include <stdio.h>
#include <string.h>

typedef char string[100];

struct nilai_tugas{
	
	int nilai;
	
};

struct siswa{
	
	string nama;
	string nim;
	
	struct nilai_tugas tugas[3];
	
};

int main(){
	
	int jumlah_data;
	
	printf("Input jumlah data yang akan dimasukan : ");
	scanf("%d",&jumlah_data);

	struct siswa mahasiswa[jumlah_data];
	
	//memasukan data
	for(int i = 0; i < jumlah_data; i++){
		
		//membersihkan buffer
		fflush(stdin);
//		while(getchar() != '\n');
		
		printf("Masukan data ke-%d\n\n",i+1);
		
		printf("Masukan nama : ");
		gets(mahasiswa[i].nama);
		
		printf("Masukan NIM : ");
		gets(mahasiswa[i].nim);
		
//		memasukan nilai tugas
		printf("\nTugas\n");
		for(int j = 0; j < 3; j++){
		
			printf("Masukan nilai ke-%d : ",j+1);
			scanf("%d",&mahasiswa[i].tugas[j].nilai);
		}	
		
	}
	
	//menampilkan data yang telah dimasukan
	printf("NIM\tNama\t\tTugas\n");
	printf("\t\tTugas1\tTugas2\tTugas3\n");
		
	for(int i = 0; i < jumlah_data; i++){
		
		printf("%s\t%s",mahasiswa[i].nim,mahasiswa[i].nama);
		
		for(int j = 0; j < 3; j++){
			printf("\t%d",mahasiswa[i].tugas[j].nilai);
		}
		printf("\n");
		
		
	}
	
}
