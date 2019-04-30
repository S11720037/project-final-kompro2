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

struct grade_huruf_angka{
	
	char huruf[2];
	int angka;
	
};


//struktur untuk menyimpan data mahasiswa
struct siswa{
	
	string nama;
	string nim;
	int total_tugas;
	int total_kuis;
	int total_project;
	int total_mid;
	int total_final;
	int total_grade;
	
	struct grade_huruf_angka grade;
	struct nilai_tugas tugas[3];
	struct nilai_kuis kuis[4];
	struct nilai_project project;
	struct nilai_mid mid;
	struct nilai_final final;
};

int main(){
	
	int jumlah_data;
	
	int nilai_tugas_min,nilai_tugas_max;
	int nilai_kuis_min,nilai_kuis_max;	
	int nilai_project_min,nilai_project_max;
	int nilai_mid_min,nilai_mid_max;
	int nilai_final_min,nilai_final_max;
	int nilai_grade_angka_min,nilai_grade_angka_max;
	
	
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
	printf("\n\nNIM\tNama\tTugas 20a\t\t\tKuis 10a\t\t\t\tProject 15a\tMID 25a\tFinal 25a\tGrade\tHuruf\n");
//	printf("\t\tI\tII\tIII\t20a\tI\tII\tIII\tIV\t10a\t15a\t\t25a\t25a\n");
		
	for(int i = 0; i < jumlah_data; i++){
		
		//menampilkan nim dan nama mahasiswa
		printf("%s\t%s",mahasiswa[i].nim,mahasiswa[i].nama);
		
		
		//menampilkan nilai tugas
		for(int j = 0; j < 3; j++){
			
			printf("\t%d",mahasiswa[i].tugas[j].nilai);
			
			mahasiswa[i].total_tugas = mahasiswa[i].tugas[j].nilai * 20 / 100;
		}
		printf("\t%d",mahasiswa[i].total_tugas);	
		
		//menampilkan nilai kuis
		int total_kuis;
		for(int j = 0; j < 4; j++){
			
			mahasiswa[i].total_kuis = mahasiswa[i].kuis[j].nilai * 15 / 100;
			
			printf("\t%d",mahasiswa[i].total_kuis);
		}
		printf("\t%d",mahasiswa[i].total_kuis);
		
		//menampilkan nilai project
		mahasiswa[i].total_project = (mahasiswa[i].project.nilai * 15 / 100);
		printf("\t%d",mahasiswa[i].total_project);
	
	
		//menampilkan nilai mid
		mahasiswa[i].total_mid = (mahasiswa[i].mid.nilai * 25 / 100);
		printf("\t\t%d",mahasiswa[i].total_mid);
	
		//menampilkan nilai final dsan grade
		mahasiswa[i].total_final = (mahasiswa[i].final.nilai * 25 / 100);
		mahasiswa[i].total_grade = mahasiswa[i].total_tugas + mahasiswa[i].total_kuis + mahasiswa[i].total_project + mahasiswa[i].total_mid + mahasiswa[i].total_final;
		printf("\t%d\t%d",mahasiswa[i].total_final,mahasiswa[i].total_grade);
	
		//menentukan grade yang didapat
//		int grade = total_tugas + total_kuis + total_project + total_mid + total_final;
//		printf("\t%d",grade);

		//menentukan grade sebagai huruf
		if(mahasiswa[i].grade.angka >= 91 && mahasiswa[i].grade.angka <= 100){
			strcpy(mahasiswa[i].grade.huruf,"A");
		}
		else if(mahasiswa[i].grade.angka >= 85 && mahasiswa[i].grade.angka <= 90){
			strcpy(mahasiswa[i].grade.huruf,"A-");
		}
		else if(mahasiswa[i].grade.angka >= 82 && mahasiswa[i].grade.angka <= 84){
			strcpy(mahasiswa[i].grade.huruf,"B+");
		}
		else if(mahasiswa[i].grade.angka >= 78 && mahasiswa[i].grade.angka <= 81){
			strcpy(mahasiswa[i].grade.huruf,"B");
		}
		else if(mahasiswa[i].grade.angka >= 75 && mahasiswa[i].grade.angka <= 77){
			strcpy(mahasiswa[i].grade.huruf,"B-");
		}
		else if(mahasiswa[i].grade.angka >= 70 && mahasiswa[i].grade.angka <= 74){
			strcpy(mahasiswa[i].grade.huruf,"C+");
		}
		else if(mahasiswa[i].grade.angka >= 67 && mahasiswa[i].grade.angka <= 69){
			strcpy(mahasiswa[i].grade.huruf,"C");
		}
		else if(mahasiswa[i].grade.angka >=60 && mahasiswa[i].grade.angka <= 66){
			strcpy(mahasiswa[i].grade.huruf,"C-");
		}
		else if(mahasiswa[i].grade.angka >=40 && mahasiswa[i].grade.angka <=50){
			strcpy(mahasiswa[i].grade.huruf,"D");
		}
		else{
			strcpy(mahasiswa[i].grade.huruf,"XX");
		}
		//menampilkan grade sebagai huruf
		printf("\t%s",mahasiswa[i].grade.huruf);
	
		
		printf("\n");
		
		
	}
	
	//mencari nilai terendah
	nilai_tugas_min = mahasiswa[0].total_tugas;
	nilai_kuis_min = mahasiswa[0].total_kuis;
	nilai_project_min = mahasiswa[0].total_project;
	nilai_final_min = mahasiswa[0].total_final;
	nilai_grade_angka_min = mahasiswa[0].total_grade;
	
	for(int i = 0; i < jumlah_data; i++){
		
		//mencari nilai tugas terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_tugas < nilai_tugas_min){
				nilai_tugas_min = mahasiswa[i].total_tugas;
			}
		}
//		printf("\n\nNilai tugas terendah : %d",nilai_tugas_min);
	
	
		//mencari nilai kuis terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_kuis < nilai_kuis_min){
				nilai_kuis_min = mahasiswa[i].total_kuis;
			}
		}
		
		//mencari nilai project terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_project < nilai_project_min){
				nilai_project_min = mahasiswa[i].total_project;
			}
		}
		
		//mencari nilai mid terendah
		nilai_mid_min = mahasiswa[0].total_mid;
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_mid < nilai_mid_min){
				nilai_mid_min = mahasiswa[i].total_mid;
			}
		}
		
		//mencari nilai final terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_final < nilai_final_min){
				nilai_final_min = mahasiswa[i].total_final;
			}
		}
		
		//mencari nilai grade terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_grade < nilai_grade_angka_min){
				nilai_grade_angka_min = mahasiswa[i].total_grade;
			}
		}
		
	}
	
	//menampilkan nilai terendah yang telah dicari
	printf("\n\nNilai tugas terendah : %d",nilai_tugas_min);
	printf("\n\nNilai kuis terendah : %d",nilai_kuis_min);	
	printf("\n\nNilai project terendah : %d",nilai_project_min);
	printf("\n\nNilai MID terendah : %d",nilai_mid_min);
	printf("\n\nNilai final terendah : %d",nilai_final_min);
	printf("\n\nNilai grade terendah : %d",nilai_grade_angka_min);		
	
	
	//mencari nilai tertinggi
	nilai_tugas_max = mahasiswa[0].total_tugas;
	nilai_kuis_max = mahasiswa[0].total_kuis;
	nilai_project_max = mahasiswa[0].total_project;
	nilai_final_max = mahasiswa[0].total_final;
	nilai_grade_angka_max = mahasiswa[0].total_grade;
	
	for(int i = 0; i < jumlah_data; i++){
		
		//mencari nilai tugas terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_tugas > nilai_tugas_max){
				nilai_tugas_max = mahasiswa[i].total_tugas;
			}
		}
//		printf("\n\nNilai tugas terendah : %d",nilai_tugas_max);
	
	
		//mencari nilai kuis terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_kuis > nilai_kuis_max){
				nilai_kuis_max = mahasiswa[i].total_kuis;
			}
		}
		
		//mencari nilai project terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_project > nilai_project_max){
				nilai_project_max = mahasiswa[i].total_project;
			}
		}
		
		//mencari nilai mid terendah
		nilai_mid_max = mahasiswa[0].total_mid;
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_mid > nilai_mid_max){
				nilai_mid_max = mahasiswa[i].total_mid;
			}
		}
		
		//mencari nilai final terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_final > nilai_final_max){
				nilai_final_max = mahasiswa[i].total_final;
			}
		}
		
		//mencari nilai grade terendah
		for(int j = 0; j < 3; j++){
			if(mahasiswa[i].total_grade > nilai_grade_angka_max){
				nilai_grade_angka_max = mahasiswa[i].total_grade;
			}
		}
		
	}
	
		//menampilkan nilai terendah yang telah dicari
	printf("\n\nNilai tugas tertinggi : %d",nilai_tugas_max);
	printf("\n\nNilai kuis tertinggi : %d",nilai_kuis_max);	
	printf("\n\nNilai project tertinggi : %d",nilai_project_max);
	printf("\n\nNilai MID tertinggi : %d",nilai_mid_max);
	printf("\n\nNilai final tertinggi : %d",nilai_final_max);
	printf("\n\nNilai grade tertinggi : %d",nilai_grade_angka_max);
	
}
