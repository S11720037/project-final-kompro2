//program final project compro2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	
	int total_tugas = 0;
	int total_kuis = 0;
	int total_project = 0;
	int total_mid = 0;
	int total_final = 0;
	int total_grade_angka = 0;
	
	
	struct grade_huruf_angka grade;
	struct nilai_tugas tugas[3];
	struct nilai_kuis kuis[4];
	struct nilai_project project;
	struct nilai_mid mid;
	struct nilai_final final;
};

int main(){
	
	struct siswa mahasiswa[100];
	
	int jumlah_data;
	int tidak_lulus = 0;
	int data_masuk = 1;
	
	//untuk menyimpan nilai minimum dan maksimum mahasiswa
	int nilai_tugas_min,nilai_tugas_max;
	int nilai_kuis_min,nilai_kuis_max;	
	int nilai_project_min,nilai_project_max;
	int nilai_mid_min,nilai_mid_max;
	int nilai_final_min,nilai_final_max;
	int nilai_grade_angka_min,nilai_grade_angka_max;
	
	int pilihan_user;

	do
	{
		
		//membuat menu pilihan untuk user menggunakan switch
		printf("\nPilihan Menu : \n");
		printf("[0] Untuk keluar\n");
		printf("[1] Memasukan data\n");
		printf("[2] Menampilkan skala grade\n");
		printf("[3] Menampilkan data yang telah di input dalam bentuk tabel\n");
		printf("[4] Menampilkan data yang telah di input dalam bentuk frekuensi grade\n");
		printf("[5] Menampilkan data yang telah di input dalam bentuk grade yang terurut\n");
		printf("Masukan pilihan : ");
		scanf("%d",&pilihan_user);
		
		switch(pilihan_user){
			
			case 1:
				
				//
				data_masuk = 2;
				system("cls");
				
				//user input jumlah data yang akan diproses
				printf("Input jumlah data yang akan dimasukan : ");
				scanf("%d",&jumlah_data);
			
				mahasiswa[jumlah_data];
				
				//memasukan data
				for(int i = 0; i < jumlah_data; i++){
					
					system("cls");
					
					//membersihkan buffer
					fflush(stdin);
					//buffer? baca ini: https://www.belajarcpp.com/tips-dan-trik/flush-buffer/
					
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
				
				//menghitung total data yang telah dimasukan
				for(int i = 0; i < jumlah_data; i++){
					
					//menghitung total data tugas mahasiswa
					for(int j = 0; j < 3; j++){
						
						mahasiswa[i].total_tugas += mahasiswa[i].tugas[j].nilai;
						
					}
					
					//menghitung total kuis
					for(int j = 0; j < 4; j++){
						mahasiswa[i].total_kuis += mahasiswa[i].kuis[j].nilai;
						
					}
					
					//menghitung total tugas mahasiswa
					mahasiswa[i].total_tugas = (mahasiswa[i].total_tugas / 3) * 20 / 100;
					
					//menghitung total kuis
					mahasiswa[i].total_kuis = (mahasiswa[i].total_kuis / 4) * 15 / 100;
					
					//menghitung total project
					mahasiswa[i].total_project = mahasiswa[i].project.nilai * 15 / 100;
					
					//menghitung total nilai mid
					mahasiswa[i].total_mid = (mahasiswa[i].mid.nilai * 25 / 100);
					
					//menghitung nilai final
					mahasiswa[i].total_final = (mahasiswa[i].final.nilai * 25 / 100);
					
					//menghitung total grade
					mahasiswa[i].total_grade_angka = mahasiswa[i].total_tugas + mahasiswa[i].total_kuis + mahasiswa[i].total_project + mahasiswa[i].total_mid + mahasiswa[i].total_final;
			
					
					//menentukan grade sebagai huruf
					if(mahasiswa[i].total_grade_angka >= 91 && mahasiswa[i].total_grade_angka <= 100){
						strcpy(mahasiswa[i].grade.huruf,"A");
					}
					else if(mahasiswa[i].total_grade_angka >= 85 && mahasiswa[i].total_grade_angka <= 90){
						strcpy(mahasiswa[i].grade.huruf,"A-");
					}
					else if(mahasiswa[i].total_grade_angka >= 82 && mahasiswa[i].total_grade_angka <= 84){
						strcpy(mahasiswa[i].grade.huruf,"B+");
					}
					else if(mahasiswa[i].total_grade_angka >= 78 && mahasiswa[i].total_grade_angka <= 81){
						strcpy(mahasiswa[i].grade.huruf,"B");
					}
					else if(mahasiswa[i].total_grade_angka >= 75 && mahasiswa[i].total_grade_angka <= 77){
						strcpy(mahasiswa[i].grade.huruf,"B-");
					}
					else if(mahasiswa[i].total_grade_angka >= 70 && mahasiswa[i].total_grade_angka <= 74){
						strcpy(mahasiswa[i].grade.huruf,"C+");
					}
					else if(mahasiswa[i].total_grade_angka >= 67 && mahasiswa[i].total_grade_angka <= 69){
						strcpy(mahasiswa[i].grade.huruf,"C");
					}
					else if(mahasiswa[i].total_grade_angka >=60 && mahasiswa[i].total_grade_angka <= 66){
						strcpy(mahasiswa[i].grade.huruf,"C-");
					}
					else if(mahasiswa[i].total_grade_angka >=40 && mahasiswa[i].total_grade_angka <=50){
						strcpy(mahasiswa[i].grade.huruf,"D");
					}
					else{
						strcpy(mahasiswa[i].grade.huruf,"XX");
					}
					
				}
					
					
				//mencari nilai terendah dan tertinggi	
				
				//inisialisasi untuk nilai minimum
				nilai_tugas_min = mahasiswa[0].total_tugas;
				nilai_kuis_min = mahasiswa[0].total_kuis;
				nilai_project_min = mahasiswa[0].total_project;
				nilai_mid_min = mahasiswa[0].total_mid;
				nilai_final_min = mahasiswa[0].total_final;
				nilai_grade_angka_min = mahasiswa[0].total_grade_angka;
				
				//inisialisasi untuk nilai maksimum
				nilai_tugas_max = mahasiswa[0].total_tugas;
				nilai_kuis_max = mahasiswa[0].total_kuis;
				nilai_project_max = mahasiswa[0].total_project;
				nilai_mid_max = mahasiswa[0].total_mid;
				nilai_final_max = mahasiswa[0].total_final;
				nilai_grade_angka_max = mahasiswa[0].total_grade_angka;
				
				for(int i = 0; i < jumlah_data; i++){
					
					//mencari nilai terendah
					
					//mencari nilai tugas terendah
					if(mahasiswa[i].total_tugas < nilai_tugas_min){
						nilai_tugas_min = mahasiswa[i].total_tugas;
					}
					
					//mencari nilai kuis terendah
					if(mahasiswa[i].total_kuis < nilai_kuis_min){
						nilai_kuis_min = mahasiswa[i].total_kuis;
					}
					
					//mencari nilai project terendah
					if(mahasiswa[i].total_project < nilai_project_min){
						nilai_project_min = mahasiswa[i].total_project;
					}
					
					//mencari nilai mid terendah
					if(mahasiswa[i].total_mid < nilai_mid_min){
						nilai_mid_min = mahasiswa[i].total_mid;
					}
					
					//mencari nilai final terendah
					if(mahasiswa[i].total_final < nilai_final_min){
						nilai_final_min = mahasiswa[i].total_final;
					}
					
					//mencari nilai grade terendah
					if(mahasiswa[i].total_grade_angka < nilai_grade_angka_min){
						nilai_grade_angka_min = mahasiswa[i].total_grade_angka;
					}
					
					//mencari nilai tertinggi
					
					//mencari nilai tugas tertinggi
					if(mahasiswa[i].total_tugas > nilai_tugas_max){
						nilai_tugas_max = mahasiswa[i].total_tugas;
					}
					
					//mencari nilai kuis tertinggi
					if(mahasiswa[i].total_kuis > nilai_kuis_max){
						nilai_kuis_max = mahasiswa[i].total_kuis;
					}
					
					//mencari nilai project tertinggi
					if(mahasiswa[i].total_project > nilai_project_max){
						nilai_project_max = mahasiswa[i].total_project;
					}
					
					//mencari nilai mid tertinggi
					if(mahasiswa[i].total_mid > nilai_mid_max){
						nilai_mid_max = mahasiswa[i].total_mid;
					}
					
					//mencari nilai final tertinggi
					if(mahasiswa[i].total_final > nilai_final_max){
						nilai_final_max = mahasiswa[i].total_final;
					}
					
					//mencari nilai grade tertinggi
					if(mahasiswa[i].total_grade_angka > nilai_grade_angka_max){
						nilai_grade_angka_max = mahasiswa[i].total_grade_angka;
					}
					
				}
					
					
					
				//mengurutkan data yang dimiliki mahasiswa
				/*
					saat pengurutan data, semua data dalam strutc mahasiswa harus diurutkan
					untuk mencegah terjadinya data yang tidak sinkron
				*/
				for(int i = 0; i < jumlah_data; i++){
						
					for(int j = 0; j < jumlah_data; j++){
						
						if(mahasiswa[i].total_grade_angka < mahasiswa[j].total_grade_angka){
							
							//menukarkan nim mahasiswa
							string temp_nim;
							strcpy(temp_nim,mahasiswa[i].nim);
							strcpy(mahasiswa[i].nim,mahasiswa[j].nim);
							strcpy(mahasiswa[j].nim,temp_nim);
							
							//menukarkan nama mahasiswa
							string temp_nama;
							strcpy(temp_nama,mahasiswa[i].nama);
							strcpy(mahasiswa[i].nama,mahasiswa[j].nama);
							strcpy(mahasiswa[j].nama,temp_nama);
							
							//menukarkan tugas mahasiswa
							for(int k = 0; k < 3; k++){
								int temp_tugas;
								temp_tugas = mahasiswa[i].tugas[k].nilai;
								mahasiswa[i].tugas[k].nilai = mahasiswa[j].tugas[k].nilai;
								mahasiswa[j].tugas[k].nilai = temp_tugas;
							}
							
							//menukarkan total tugas mahasiswa
							int temp_total_tugas;
							temp_total_tugas = mahasiswa[i].total_tugas;
							mahasiswa[i].total_tugas = mahasiswa[j].total_tugas;
							mahasiswa[j].total_tugas = temp_total_tugas;
							
							//menukarkan kuis mahasiswa
							for(int k = 0; k < 4; k++){
								int temp_kuis;
								temp_kuis = mahasiswa[i].kuis[k].nilai;
								mahasiswa[i].kuis[k].nilai = mahasiswa[j].kuis[k].nilai;
								mahasiswa[j].kuis[k].nilai = temp_kuis;
							}
							
							//menukarkan total kuis mahasiswa
							int temp_total_kuis;
							temp_total_kuis = mahasiswa[i].total_kuis;
							mahasiswa[i].total_kuis = mahasiswa[j].total_kuis;
							mahasiswa[j].total_kuis = temp_total_kuis;
							
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
							temp_angka = mahasiswa[i].total_grade_angka;
							mahasiswa[i].total_grade_angka = mahasiswa[j].total_grade_angka;
							mahasiswa[j].total_grade_angka = temp_angka;
							
							//mengurukan grade huruf mahasiswa
							string temp_string;
							strcpy(temp_string,mahasiswa[i].grade.huruf);
							strcpy(mahasiswa[i].grade.huruf,mahasiswa[j].grade.huruf);
							strcpy(mahasiswa[j].grade.huruf,temp_string);
							
						}
						
					}
					
				}
				
				//
			system("cls");
			break;
			
			case 2:
				//menampilkan skala grade
				//
				system("cls");
				printf("%s\t%s\n","Nilai akhir","Grade");
				printf("%s\t%s\n","==========","==========");
				printf("%s\t\t%s\n","91-100","A");
				printf("%s\t\t%s\n","85-90","A-");
				printf("%s\t\t%s\n","82-84","B+");
				printf("%s\t\t%s\n","78-81","B");
				printf("%s\t\t%s\n","75-77","B-");
				printf("%s\t\t%s\n","70-74","C+");
				printf("%s\t\t%s\n","67-69","C");
				printf("%s\t\t%s\n","60-66","C-");
				printf("%s\t\t%s\n","40-59","-");
				//
			break;
			
			case 3:
				//
				//menampilkan data dalam tabel
				if(data_masuk == 1){
					system("cls");
					printf("Belum ada data yang di input\n");
				}
				else if(data_masuk != 1){
				
					system("cls");
					printf("+--------+----------------------+------------------------------+-------------------------------+----------+-----+----------+----------+----------+\n");
					printf("|%-8s|%-22s|%-30s|%-31s|%-10s|%-5s|%-10s|%-10s|%-10s|\n","NIM","Nama","Tugas","Kuis","Project","MID","Final","Grade","Huruf");
					printf("+--------+----------------------+------------------------------+-------------------------------+----------+-----+----------+----------+----------+\n");
					printf("|%9s%23s%31s%32s%11s%6s%11s%11s%11s","|","|","|","|","|","|","|","|","|");
					printf("\n");
					printf("|\t\ |\t\t\t|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\t  |%s\t|%-10s|\t      |\t\t |","Tugas1","Tugas2","Tugas3","Total 20%","Kuis1","Kuis2","Kuis3","Kuis4","Kuis15%","15%","25%","25%");
					printf("\n");
					printf("+--------+----------------------+------+------+------+---------+-----+-----+-----+-----+-------+----------+-----+----------+----------+----------+\n");
					printf("%s%9s%23s%7s%7s%7s%10s%6s%6s%6s%6s%8s%11s%6s%11s%11s%11s","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|");
					printf("\n");
						
					for(int i = 0; i < jumlah_data; i++){
						
						//menampilkan nim dan nama mahasiswa
						printf("|%-8s|%-22s|",mahasiswa[i].nim,mahasiswa[i].nama);
						
						
						//menampilkan nilai tugas
						for(int j = 0; j < 3; j++){
							
							printf("%-6d|",mahasiswa[i].tugas[j].nilai);	
							
						}
						printf("%-9d|",mahasiswa[i].total_tugas);	
						
						//menampilkan nilai kuis
						for(int j = 0; j < 4; j++){
							
							printf("%-5d|",mahasiswa[i].kuis[j].nilai);
						}
						printf("%-7d|",mahasiswa[i].total_kuis);
						
						//menampilkan nilai project
						printf("%-10d|",mahasiswa[i].total_project);
					
						//menampilkan nilai mid
						printf("%-5d|",mahasiswa[i].total_mid);
					
						//menampilkan nilai final dan grade
						printf("%-10d|%-10d|",mahasiswa[i].total_final,mahasiswa[i].total_grade_angka);
					
						//menampilkan grade sebagai huruf
						printf("%-10s|",mahasiswa[i].grade.huruf);
						
						printf("\n");
						
					printf("%s%9s%23s%7s%7s%7s%10s%6s%6s%6s%6s%8s%11s%6s%11s%11s%11s","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|");
					printf("\n");
					printf("+--------+----------------------+------+------+------+---------+-----+-----+-----+-----+-------+----------+-----+----------+----------+----------+\n");		
						
					
					}
					
					//menampilkan nilai terendah yang telah dicari
					printf("\nNilai Terendah\t\t\t\t\t\t%d\t\t\t\t%d\t%d\t   %d\t  %d\t     %d",nilai_tugas_min,nilai_kuis_min,nilai_project_min,nilai_mid_min,nilai_final_min,nilai_grade_angka_min);	
					
					//menampilkan nilai terendah yang telah dicari
					printf("\nNilai Tertinggi\t\t\t\t\t\t%d\t\t\t\t%d\t%d\t   %d\t  %d\t     %d",nilai_tugas_max,nilai_kuis_max,nilai_project_max,nilai_mid_max,nilai_final_max,nilai_grade_angka_max);
				
					//menghitung jumlah mahasiswa yang tidak lulus
					//mencari siswa yang tidak lulus
					for(int k = 0; k < jumlah_data; k++){
						
						if(mahasiswa[k].total_grade_angka < 67){
							tidak_lulus += 1;
						}
						
					}
					//menampilkan mahasiswa yang tidak lulus
					printf("\n\nJumlah mahasiswa yang tidak lulus = %d",tidak_lulus);
					
					printf("\n");
				}
			//	
			break;
			
			
			case 4:
				//
				//menampilkan hasil pengurutan sebagai frekuensi
				if(data_masuk == 1){
					system("cls");
					printf("Belum ada data yang di input\n");
				}
				else if(data_masuk != 1){
			
					system("cls");
					printf("Frekuensi kemunculan :\n");
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
				}
				//
			break;
			
			case 5:
				//
				//menampilkan nilai grade yang telah di urutkan
				if(data_masuk == 1){
					system("cls");
					printf("Belum ada data yang di input\n");
				}
				else if(data_masuk != 1){
				
					system("cls");
					printf("Hasil pengurutan grade:\n");
					for(int i = 0; i < jumlah_data; i++){
						
						printf("%s = %d\n",mahasiswa[i].nama,mahasiswa[i].total_grade_angka);
						
					}
				}
				//
			break;
			
			case 0:
			pilihan_user = 777;	
				
		}
	
}while(pilihan_user != 777);
	
	
	return 0;
}


