#include "Header.h"

int main() {
	CT ct;
	DSCT ds;
	int menu;
	do
	{
		cout << "\n**************CHUONG TRINH QUAN LY CAU THU**************\n";
		cout << "=========================MENU===========================\n";
		cout << " 1. Moi nhap danh sach cau thu.\n";
		cout << " 2. Xuat danh sach cau thu.\n";
		cout << " 3. Mo File danh sach cau thu.\n";
		cout << " 4. Them mot cau thu moi.\n";
		cout << " 5. Xoa mot cau thu khoi.\n";
		cout << " 6. Tim kiem cau thu.\n";
		cout << " 7. Cap nhat.\n";
		cout << " 8. Chon che do hien thi danh sach. \n";
		cout << " 9. Bang xep hang cau thu. \n";
		cout << " 10. Xoa man hinh.\n";
		cout << " 0. Thoat khoi chuong trinh.\n";
		cout << "=======================================================\n";
		cout << "Moi ban chon chuc nang: ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			break;
		case 1:
			NhapDSCT(ds);
			break;
		case 2:
			XuatDSCT(ds);
			LuuDSCT(ds);
			break;
		case 3:
			MoDSCT(ds);
			break;
		case 4:
			cout << "Nhap thong tin cho cau thu can them \n";
			NhapCauThu(ct);
			them_cauthu(ds, ct);
			XuatDSCT(ds);
			break;
		case 5:
			cout << "Nhap ma cau thu hoac ten cau thu can xoa: "; cin >> ct.mact;
			xoa_cauthu(ds, ct.mact, ct.Hoten);
			XuatDSCT(ds);
			break;
		case 6:
			cout << "Nhap ma cau thu hoac ten cau thu: ";
			cin >> ct.mact;
			tim_kiem(ds, ct.mact);
			break;
		case 7:
			menuCapnhat(ds, ct.mact);
			break;
		case 8:
			menuHienthi(ds);
			break;
		case 9:
			XuatBangXepHang(ds);
			break;
		case 10:
			system("cls");
			break;
		default:
			cout << "Chuc nang khong ton tai.Vui long thu lai";
			break;
		}
	} while (menu!=0);
}