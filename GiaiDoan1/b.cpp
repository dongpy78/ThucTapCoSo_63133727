// Thu vien --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Thu vien --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Bien so ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
struct thi_sinh {
    int mssv;
    char ten[25];
    float toan, ly, hoa, diem_tong;
    int khu_vuc;
};

thi_sinh hs[50];
int n;
// Bien so ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Chuong trinh con  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Ham hien thi ket qua ra bang
void in() {
    printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 
    printf("\n\t| %s:    | %15s:      | %7s:\t| %8s:\t| %9s:\t| %10s:\t| %10s:\t|", "MSSV", "Ho & Ten", "Toan", "Ly", "Hoa", "Khu vuc", "Tong diem");
    printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 
    for (int i = 0; i < n; i++) {
        printf("\n\t| %d | %21s |\t%g\t|\t%g\t|\t%g\t|\t%d\t|\t%g\t|", hs[i].mssv, hs[i].ten, hs[i].toan, hs[i].ly, hs[i].hoa, hs[i].khu_vuc, hs[i].diem_tong); 
    }
    printf("\n\t-----------------------------------------------------------------------------------------------------------------\n"); 
}

// Nhap du lieu
void du_lieu_tung_thi_sinh(thi_sinh &hs) {
    char s[10];
	do {
        printf("\n + MSSV: ");
        gets(s);

		int x = strlen(s);
		if (x == 8 && s[0] != '0') {
            hs.mssv = atoi(s);
			break;
		}
        else printf(" MSSV co do dai 8 ki tu va chi bao gom cac so tu 0 - 9 !. Hay nhap lai:");
	} while (1>0);

    printf(" + Ho va ten: ");
    gets(hs.ten);
    
    float t, l, h;
    do {
        printf(" + Diem Toan: ");
        scanf("%f", &t);
        if (t >= 0 && t <= 10) break;
        else printf(" Diem dao dong tu 0 - 10 !. Hay hap lai:\n");
    } while (1>0);
    hs.toan = t;

    do {
        printf(" + Diem Ly: ");
        scanf("%f", &l);
        if (l >= 0 && l <= 10) break;
        else printf(" Diem dao dong tu 0 - 10 !. Hay hap lai:\n");
    } while (1>0);
    hs.ly = l;

    do {
        printf(" + Diem Hoa: ");
        scanf("%f", &h);
        if (h >= 0 && h <= 10) break;
        else printf(" Diem giao dong tu 0 - 10 !. Hay hap lai:\n");
    } while (1>0);
    hs.hoa = h;

    do {
        printf(" + Khu vuc: ");
        scanf("%d", &hs.khu_vuc);
    } while (!(hs.khu_vuc == 1 || hs.khu_vuc == 0));

    hs.diem_tong = t + l + h;
    if (hs.khu_vuc == 1) hs.diem_tong += 1;
}

// Nhap du lieu thi sinh dau vao
// Cau a
void nhap() {
    for (int i = 0; i < n; i++) {
        printf("\n Thi sinh thu %d:", i+1);
        fflush(stdin);
        du_lieu_tung_thi_sinh(hs[i]);
    }
}

// Cau b
void sap_xep_tang_dan_the_MSSV() {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (hs[i].mssv > hs[j].mssv) {
                thi_sinh x = hs[i];
                hs[i] = hs[j];
                hs[j] = x;
            }
    in();
}

// Cau c
void max_toan() {
    float max = hs[0].toan;
    for (int i = 1; i < n; i++) {
        if (hs[i].toan > max) max = hs[i].toan;
    }

    printf("\n\t-------------------------------------------------"); 
    printf("\n\t| %s:    | %15s:      | %7s:\t|", "MSSV", "Ho & Ten", "Toan");
    printf("\n\t-------------------------------------------------"); 

    for (int i = 0; i < n; i++) {
        if (hs[i].toan == max) 
            printf("\n\t| %d | %21s |\t%g\t|", hs[i].mssv, hs[i].ten, hs[i].toan); 
    }
    printf("\n\t-------------------------------------------------\n"); 
}

// Cau d
void thu_khoa() {
    int diem_thu_khoa = hs[0].diem_tong;
    for (int i = 1; i < n; i++) {
        if (hs[i].diem_tong > diem_thu_khoa) diem_thu_khoa = hs[i].diem_tong; // Timm diem tong cao nhat trong cac hoc sinh nhap vao
    }

	printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 
    printf("\n\t| %s:    | %15s:      | %7s:\t| %8s:\t| %9s:\t| %10s:\t| %10s:\t|", "MSSV", "Ho & Ten", "Toan", "Ly", "Hoa", "Khu vuc", "Tong diem");
    printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 

    for (int i = 0; i < n; i++) {
        if (hs[i].diem_tong == diem_thu_khoa)
            printf("\n\t| %d | %21s |\t%g\t|\t%g\t|\t%g\t|\t%d\t|\t%g\t|", hs[i].mssv, hs[i].ten, hs[i].toan, hs[i].ly, hs[i].hoa, hs[i].khu_vuc, hs[i].diem_tong); 
    }
    printf("\n\t-----------------------------------------------------------------------------------------------------------------\n"); 
}

// Cau e
void sap_xep_theo_tong_diem_cao_xuong_thap() {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (hs[i].diem_tong < hs[j].diem_tong) {
                thi_sinh x = hs[i];
                hs[i] = hs[j];
                hs[j] = x;
            }
        }
    }

	printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 
    printf("\n\t| %s:    | %15s:      | %7s:\t| %8s:\t| %9s:\t| %10s:\t| %10s:\t|", "MSSV", "Ho & Ten", "Toan", "Ly", "Hoa", "Khu vuc", "Tong diem");
	printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 

    for (int i = 0; i < n; i++) {
        printf("\n\t| %d | %21s |\t%g\t|\t%g\t|\t%g\t|\t%d\t|\t%g\t|", hs[i].mssv, hs[i].ten, hs[i].toan, hs[i].ly, hs[i].hoa, hs[i].khu_vuc, hs[i].diem_tong); 
    }
	printf("\n\t-----------------------------------------------------------------------------------------------------------------\n"); 
}

// Cau f
void thi_sinh_thi_dau() {
    printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 
    printf("\n\t| %s:    | %15s:      | %7s:\t| %8s:\t| %9s:\t| %10s:\t| %10s:\t|", "MSSV", "Ho & Ten", "Toan", "Ly", "Hoa", "Khu vuc", "Tong diem");
	printf("\n\t-----------------------------------------------------------------------------------------------------------------"); 

    for (int i = 0; i < n; i++) {
        if (hs[i].diem_tong >= 15)
            printf("\n\t| %d | %21s |\t%g\t|\t%g\t|\t%g\t|\t%d\t|\t%g\t|", hs[i].mssv, hs[i].ten, hs[i].toan, hs[i].ly, hs[i].hoa, hs[i].khu_vuc, hs[i].diem_tong); 
    }
	printf("\n\t-----------------------------------------------------------------------------------------------------------------\n"); 
}
// Chuong trinh con  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// Chuong trinh chinh  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main() {
    printf("\n Nhap so thi sinh: "); scanf("%d", &n);
    nhap();

    getchar();
    printf("\n a) Danh sach sinh vien vua nhap:");
    in();

    getchar();
    printf("\n b) Danh sach sinh vien duoc sap xep tang dan theo MSSV:");
    sap_xep_tang_dan_the_MSSV();

    getchar();
    printf("\n c) Thi sinh co diem Toan cao nhat:");
    max_toan();

    getchar();
    printf("\n d) Thi sinh thu khoa:");
    thu_khoa();

    getchar();
    printf("\n e) Danh sach thi sinh duoc sap xep theo tong diem, tu cao xuong thap:");
    sap_xep_theo_tong_diem_cao_xuong_thap();

    getchar();
    printf("\n f) Danh sach thi sinh thi dau:");
    thi_sinh_thi_dau();
}
// Chuong trinh chinh  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//