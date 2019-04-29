#include <stdio.h>
#include <string.h>

typedef char string[100];

//struktur untuk tugas
struct nilai_tugas{
	
	int nilai;
	
};

//struktur untuk kuis
struct nilai_kuis{
	
	int nilai;
	
};

//struktur untuk nilai projek
struct nilai_project{
	
	int nilai;
	
};

//struktur untuk nilai mid semester
struct nilai_mid{
	
	int nilai;
	
};

//struktur untuk nilai final
struct nilai_final{
	
	int nilai;
	
};

//struktur untuk menyimpan data mahasiswa
struct siswa{
	
	string nama;
	string nim;
	
	struct nilai_tugas tugas[3];
	struct nilai_kuis kuis[4];
	struct nilai_project project;
	struct nilai_mid mid;
	struct nilai_final final;
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
		
		//memasukan nilai kuis
		printf("\nKuis\n");
		for(int j = 0; j < 4; j++){
		
		printf("Masukan nilai ke-%d : ",j+1);
		scanf("%d",&mahasiswa[i].kuis[j].nilai);
		}
		
		//masukan nilai project
		printf("\nProject\n");
		printf("Masukan nilai : ");
		scanf("%d",&mahasiswa[i].project.nilai);
		
		
		//memasukan nilai mid
		printf("\nMID\n");
		printf("Masukan nilai : ");
		scanf("%d",&mahasiswa[i].mid.nilai);
		
		//memasukan nilai final
		printf("\nFinal\n");
		printf("Masukan nilai : ");
		scanf("%d",&mahasiswa[i].final.nilai);
		
	}
	
	//menampilkan data yang telah dimasukan
	printf("NIM\tNama\tTugas 20a\t\t\tKuis 10a\t\t\tProject 15a\tMID 25a\tFinal 25a\n");
	printf("\t\tI\tII\tIII\t20a\tI\tII\tIII\tIV\t10a\t15a\t25a\t25a\n");
		
	for(int i = 0; i < jumlah_data; i++){
		
		printf("%s\t%s",mahasiswa[i].nim,mahasiswa[i].nama);
		
		//menampilkan nilai tugas
		
		int total_tugas = 0;
		
		for(int j = 0; j < 3; j++){
			
			total_tugas = mahasiswa[i].tugas[j].nilai * 20 / 100;
			
			printf("\t%d",mahasiswa[i].tugas[j].nilai);
		}
		printf("\t%d",total_tugas);	
		
		//menampilkan nilai kuis
		int total_kuis;
		for(int j = 0; j < 4; j++){
			
			total_kuis = mahasiswa[i].kuis[j].nilai * 10 / 100;
			
			printf("\t%d",mahasiswa[i].kuis[j].nilai);
		}
		printf("\t%d",total_kuis);
		
		//menampilkan nilai project
		printf("\t%d",mahasiswa[i].project.nilai * 15 / 100);
	
	
		//menampilkan nilai mid
		printf("\t%d",mahasiswa[i].mid.nilai * 25 / 100);
	
		//menampilkan nilai final
		printf("\t%d",mahasiswa[i].final.nilai * 25 / 100);
	
		printf("\n");
		
		
	}
	
}
