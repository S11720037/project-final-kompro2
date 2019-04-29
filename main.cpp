#include <stdio.h>
#include <string.h>

typedef char string[100];

//struktur untuk tugas
struct nilai_tugas{
	
	int nilai;
	
};

//struktur untuk menyimpan data mahasiswa
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
	printf("NIM\tNama\t\tTugas 20%\n");
	printf("\t\tI\tII\tIII\t20%\n");
		
	for(int i = 0; i < jumlah_data; i++){
		
		printf("%s\t%s",mahasiswa[i].nim,mahasiswa[i].nama);
		
		//menampilkan nilai tugas
		
		int total_tugas = 0;
		
		for(int j = 0; j < 3; j++){
			
			total_tugas += mahasiswa[i].tugas[j].nilai * 20 / 100;
			
			printf("\t%d",mahasiswa[i].tugas[j].nilai);
		}
		printf("\t%d",total_tugas);	
	
		printf("\n");
		
		
	}
	
}
