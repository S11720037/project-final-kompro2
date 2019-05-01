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
	
	
	struct grade_huruf_angka grade;
	struct nilai_tugas tugas[3];
	struct nilai_kuis kuis[4];
	struct nilai_project project;
	struct nilai_mid mid;
	struct nilai_final final;
};

int main(){
	
	int jumlah_data;
	int tidak_lulus = 0;
	
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
//	printf("=================================================================================================================================================================\n");
//	printf("=\t\t=\t\t=\t\t\t\t=\t\t\t\t\t=\t      =\t\t=\t    =\n");
//	printf("= NIM\t\t= Nama\t\t= Tugas 20a\t\t\t= Kuis 10a\t\t\t\t= Project 15a = MID 25a = Final 25a = Grade = Huruf =\n");
//	printf("\t\t=\t\t=\t\t\t\t=\t\t\t\t\t=\t\t=\t  =\t=\t=\t=\n");
//	printf("=================================================================================================================================================================\n");	
//	printf("=\t\t=\t=\t=\t=\t=\t=\t=\t=\t=\t=\t\t=\t\t=\t\t=\t\t=\n");
//	printf("=\t\t= I\t= II\t= III\t= 20a\t= I\t= II\t= III\t= IV\t= 10a\t= 15a\t\t= 25a\t\t= 25a\t\t=\t\t=\n");
//	printf("=\t\t=\t=\t=\t=\t=\t=\t=\t=\t=\t=\t\t=\t\t=\t\t=\t\t=\n");
//	printf("=================================================================================================================================================================\n");	
//	printf("=\t=\t=\t=\t=\t=\t=\t=\t=\t=\t=\t=\t\t=\t\t=\t\t=\t\t=\n");

//	printf("==================================================================================================================================================================\n");
//	
//	printf("NIM\tNama\t\tTugas\t\t\t\tKuis\t\t\t\t\tProject\tMID\tFinal\tGrade\tHUruf\n");
//	printf("==================================================================================================================================================================\n");
//	printf("\t\t\t1\t2\t3\t20a\t1\t2\t3\t4\t15a\t15a\t25a\t25a\t\n");

	printf("+------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|%-8s|%-22s|%-30s|%-31s|%-10s|%-5s|%-10s|%-10s|%-10s|\n","NIM","Nama","Tugas","Kuis","Project","MID","Final","Grade","Huruf");
	printf("|\t\ |\t\t\t|\n");
	printf("|\t\ |\t\t\t|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\t  |%s\t|%-10s|\t      |\t\t |","Tugas1","Tugas2","Tugas3","Total 20a","Kuis1","Kuis2","Kuis3","Kuis4","Kuis15a","15a","25a","25a");
	printf("\n");
		
	for(int i = 0; i < jumlah_data; i++){
		
		//menampilkan nim dan nama mahasiswa
		printf("|%-8s|%-22s|",mahasiswa[i].nim,mahasiswa[i].nama);
		
		
		//menampilkan nilai tugas
		for(int j = 0; j < 3; j++){
			
			printf("%-6d|",mahasiswa[i].tugas[j].nilai);
			
			mahasiswa[i].total_tugas = mahasiswa[i].tugas[j].nilai * 20 / 100;
		}
		printf("%-9d|",mahasiswa[i].total_tugas);	
		
		//menampilkan nilai kuis
		int total_kuis;
		for(int j = 0; j < 4; j++){
			
			mahasiswa[i].total_kuis = mahasiswa[i].kuis[j].nilai * 15 / 100;
			
			printf("%-5d|",mahasiswa[i].kuis[j].nilai);
		}
		printf("%-7d|",mahasiswa[i].total_kuis);
		
		//menampilkan nilai project
		mahasiswa[i].total_project = (mahasiswa[i].project.nilai * 15 / 100);
		printf("%-10d|",mahasiswa[i].total_project);
	
	
		//menampilkan nilai mid
		mahasiswa[i].total_mid = (mahasiswa[i].mid.nilai * 25 / 100);
		printf("%-5d|",mahasiswa[i].total_mid);
	
		//menampilkan nilai final dan grade
		mahasiswa[i].total_final = (mahasiswa[i].final.nilai * 25 / 100);
		mahasiswa[i].grade.angka = mahasiswa[i].total_tugas + mahasiswa[i].total_kuis + mahasiswa[i].total_project + mahasiswa[i].total_mid + mahasiswa[i].total_final;
		printf("%-10d|%-10d|",mahasiswa[i].total_final,mahasiswa[i].grade.angka);
	
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
		printf("%-10s|",mahasiswa[i].grade.huruf);
	
		
		printf("\n");
		
		
	}
	
	//mencari nilai terendah
	nilai_tugas_min = mahasiswa[0].total_tugas;
	nilai_kuis_min = mahasiswa[0].total_kuis;
	nilai_project_min = mahasiswa[0].total_project;
	nilai_final_min = mahasiswa[0].total_final;
	nilai_grade_angka_min = mahasiswa[0].grade.angka;
	
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
			if(mahasiswa[i].grade.angka < nilai_grade_angka_min){
				nilai_grade_angka_min = mahasiswa[i].grade.angka;
			}
		}
		
	}
	
	//menampilkan nilai terendah yang telah dicari
	printf("\nNilai tugas terendah : %d",nilai_tugas_min);
	printf("\nNilai kuis terendah : %d",nilai_kuis_min);	
	printf("\nNilai project terendah : %d",nilai_project_min);
	printf("\nNilai MID terendah : %d",nilai_mid_min);
	printf("\nNilai final terendah : %d",nilai_final_min);
	printf("\nNilai grade terendah : %d",nilai_grade_angka_min);		
	
	
	//mencari nilai tertinggi
	nilai_tugas_max = mahasiswa[0].total_tugas;
	nilai_kuis_max = mahasiswa[0].total_kuis;
	nilai_project_max = mahasiswa[0].total_project;
	nilai_final_max = mahasiswa[0].total_final;
	nilai_grade_angka_max = mahasiswa[0].grade.angka;
	
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
			if(mahasiswa[i].grade.angka > nilai_grade_angka_max){
				nilai_grade_angka_max = mahasiswa[i].grade.angka;
			}
		}
		
	}
	
	//menampilkan nilai terendah yang telah dicari
	printf("\nNilai tugas tertinggi : %d",nilai_tugas_max);
	printf("\nNilai kuis tertinggi : %d",nilai_kuis_max);	
	printf("\nNilai project tertinggi : %d",nilai_project_max);
	printf("\nNilai MID tertinggi : %d",nilai_mid_max);
	printf("\nNilai final tertinggi : %d",nilai_final_max);
	printf("\nNilai grade tertinggi : %d",nilai_grade_angka_max);
	
	
	//mencari siswa yang tidak lulus
	for(int i = 0; i < jumlah_data; i++){
		
		if(mahasiswa[i].grade.angka < 67){
			tidak_lulus += 1;
		}
		
	}
	
	printf("\nJumlah mahasiswa yang tidak lulus = %d",tidak_lulus);
	
	printf("\n");
	
	
//menampilkan nilai frekuensi nilai grade
	//sebelum ditampilkan, data harus di urutkan dahulu
	/*
		saat pengurutan data, semua data dalam strutc mahasiswa harus diurutkan
		untuk mencegah terjadinya data yang tidak sinkron
	*/
	
	for(int i = 0; i < jumlah_data; i++){
			
		for(int j = 0; j < jumlah_data; j++){
			
			if(mahasiswa[i].grade.angka > mahasiswa[j].grade.angka){
				
				//mengurutkan nama mahasiswa
				string temp_nama;
				strcpy(temp_nama,mahasiswa[i].nama);
				strcpy(mahasiswa[i].nama,mahasiswa[j].nama);
				strcpy(mahasiswa[j].nama,temp_nama);
				
				//menurutkan tugas mahasiswa
				int temp_tugas;
				temp_tugas = mahasiswa[i].total_tugas;
				mahasiswa[i].total_tugas = mahasiswa[j].total_tugas;
				mahasiswa[j].total_tugas = temp_tugas;
				
				//mengurutkan kuis mahasiswa
				int temp_kuis;
				temp_kuis = mahasiswa[i].total_kuis;
				mahasiswa[i].total_kuis = mahasiswa[j].total_kuis;
				mahasiswa[j].total_kuis = temp_kuis;
				
				//mengurutkan project mahasiswa
				int temp_project;
				temp_project = mahasiswa[i].total_project;
				mahasiswa[i].total_project = mahasiswa[j].total_project;
				mahasiswa[j].total_project = temp_project;
				
				//mengurutkan nilai mid mahasiswa
				int temp_mid;
				temp_mid = mahasiswa[i].total_mid;
				mahasiswa[i].total_mid = mahasiswa[j].total_mid;
				mahasiswa[j].total_mid = temp_mid;
				
				//mengurutkan nilai final mahasiswa
				int temp_final;
				temp_final = mahasiswa[i].total_final;
				mahasiswa[i].total_final = mahasiswa[j].total_final;
				mahasiswa[j].total_final = temp_final;
				
				
				//mengurutkan grade angka mahasiswa
				int temp_angka;
				temp_angka = mahasiswa[i].grade.angka;
				mahasiswa[i].grade.angka = mahasiswa[j].grade.angka;
				mahasiswa[j].grade.angka = temp_angka;
				
				//mengurukan grade huruf mahasiswa
				string temp_string;
				strcpy(temp_string,mahasiswa[i].grade.huruf);
				strcpy(mahasiswa[i].grade.huruf,mahasiswa[j].grade.huruf);
				strcpy(mahasiswa[j].grade.huruf,temp_string);
				
				
				
			}
			
		}
		
	}	
	
	//hasil pengurutan
//	for(int i = 0; i < jumlah_data; i++){
//		
//		printf("Hasil pengurutan : %s\n",mahasiswa[i].grade.huruf);
//		
//	}
	
	//menampilkan hasil pengurutan sebagai frekuensi
	for(int i = 0; i < jumlah_data; i++){
		
		int counter = 0;
		
		for(int j = 0; j < jumlah_data; j++){
			
			int temp;
			
			temp = strcmp(mahasiswa[i].grade.huruf,mahasiswa[j].grade.huruf);
			
			if(temp == 0){
				
				counter += 1;
				
			}
			
		}
		
		int temp;
		
		temp = strcmp(mahasiswa[i].grade.huruf,mahasiswa[i-1].grade.huruf);
		
		if(temp != 0){
			
			printf("%s muncul = %d\n",mahasiswa[i].grade.huruf,counter);
			
		}
	}
	

//menampilkan nilai grade yang telah di urutkan
printf("\n============================================\n");
printf("Hasil pengurutan grade\n");
for(int i = 0; i < jumlah_data; i++){
	
	printf("%s = %d\n",mahasiswa[i].nama,mahasiswa[i].grade.angka);
	
}

	
	
	return 0;
}
