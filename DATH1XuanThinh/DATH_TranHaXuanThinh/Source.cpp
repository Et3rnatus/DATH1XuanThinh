#include"Header.h"
void NhapCauThu(CT &ct) {
	cin.ignore();
	cout << "Ma cau thu: ";
	cin.getline(ct.mact,10);
	cout << "Ho va ten cau thu: ";
	cin.getline(ct.Hoten,30);
	cout << "Quoc tich: ";
	cin.getline(ct.Quoctich, 15);
	cout << "So ao: ";
	cin >> ct.Soao;
	cout << "So ban thang: ";
	cin >> ct.sobanthang;
	cout << "The vang: ";
	cin >> ct.thevang;
	cout << "The do: ";
	cin >> ct.thedo;
}
void XuatCauThu(CT ct) {
	cout << setw(20) << left << ct.mact << setw(25) << left << ct.Hoten << setw(20) << left << ct.Quoctich << setw(10) << left << ct.Soao << setw(15) << left << ct.sobanthang << setw(15) << left << ct.thevang << setw(15) << left << ct.thedo << endl;
}
void NhapDSCT(DSCT &ct) {
	cout << "Nhap danh sach cau thu: ";
	cin >> ct.soluong;
	for (int i = 0; i < ct.soluong; i++)
	{
		cout << "Cau thu thu [" << i << "]: ";
		NhapCauThu(ct.ds[i]);
	}
}	
void XuatDSCT(DSCT l) {
	cout <<setw(20)<<left<< "\nMa cau thu"<< setw(25)<<left<< "Ho va ten" << setw(20)<<left << "Quoc tich" << setw(10)<<left << "So ao" << setw(15)<<left << "So ban thang"<< setw(15)<<left<<"The vang" << setw(15)<<left<<"The do" << endl;
	for (int i = 0; i < l.soluong; i++)
	{
		cout << endl;
		XuatCauThu(l.ds[i]);
	}
}
bool Kiemtramact(DSCT &dsct, char* ma) {
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].mact,ma)==0) {
			return true;
		}
	}
	return false;
}
bool kiemtra(const char mact[]) {
	if(strlen(mact)>=2)
	{
		if (mact[0] == 'c'&&mact[1] == 't') {
			return true;
		}
	}
	return false;
}
void them_cauthu(DSCT &dsct, CauThu ct) {
	if (Kiemtramact(dsct, ct.mact)) {
		cout << "\nMa cau thu nay da ton tai, vui long thu lai";	
	}
	else {
		if (dsct.soluong >= N) {
			cout << "\nDanh sach da day, khong the them cau thu moi";
		}
		else if (!kiemtra(ct.mact)){
			cout << "\nMa cau thu khong hop le";
		}
		else {
			dsct.ds[dsct.soluong] = ct;
			dsct.soluong++;
			cout << "\nThem cau thu thanh cong";
		}
	}
}
void xoa_cauthu(DSCT &dsct,char* ma,char* ten) {
	int vitri = -1;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].mact,ma)==0||strcmp(dsct.ds[i].Hoten,ten)==0) {
			vitri = i;
			break;
		}
	}
	if (vitri == -1) {
		cout << "\nKhong tim thay cau thu";
	}
	else {
		for (int i = vitri; i < dsct.soluong-1; i++)
		{
			dsct.ds[i] = dsct.ds[i + 1];
		}
		dsct.soluong--;
		cout << "\nDa xoa cau thu";
	}
}
void tim_kiem(DSCT &dsct, char* ma) {
	bool found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strstr(dsct.ds[i].mact, ma) != NULL|| strstr(dsct.ds[i].Hoten,ma)!=NULL) {
			cout << "Ma CT: " << dsct.ds[i].mact << ", Ho ten: " << dsct.ds[i].Hoten << ", So ao: " << dsct.ds[i].Soao << endl;
			found = 1;
		}
	}
	if (!found) {
		cout << "Khong tim thay cau thu";
	}
}
void Nameupdate(CT &ct) {
	cout << "\nNhap ten moi: ";
	cin.ignore();
	cin.getline(ct.Hoten, sizeof(ct.Hoten));
}
void CapNhatTen(DSCT &dsct,char* ma ) {
	int found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].mact,ma)==0) {
			Nameupdate(dsct.ds[i]);
			found = 1;	
			break;
		}
	}
	if (found == 0) {
		cout << "\nKhong tim thay ma cau thu trong danh sach";
	}
}
void QuoctichUpdate(CT &ct) {
	cout << "\nNhap quoc tich moi: ";
	cin.ignore();
	cin.getline(ct.Quoctich, sizeof(ct.Quoctich));
}
void CapNhatQuoctich(DSCT &dsct, char* ma) {
	int found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].mact, ma) == 0) {
			QuoctichUpdate(dsct.ds[i]);
			found = 1;
			break;
		}
	}
	if (found == 0) {
		cout << "\nKhong tim thay ma cau thu trong danh sach";
	}
}
void SoaoUpdate(CT &ct) {
	cout << "\nNhap so ao moi: ";
	cin >> ct.Soao;
}
void CapNhatSoao(DSCT &dsct, char* ma) {
	int found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].mact, ma) == 0) {
			SoaoUpdate(dsct.ds[i]);
			found = 1;
			break;
		}
	}
	if (found == 0) {
		cout << "\nKhong tim thay ma cau thu trong danh sach";
	}
}
void Capnhatbanthang(DSCT &dsct, char *ten, int sobanthangmoi) {
	int found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].Hoten, ten) == 0||strcmp(dsct.ds[i].mact,ten)==0) {
			dsct.ds[i].sobanthang += sobanthangmoi;
			found = 1;
			break;
		}
	}
	if (found == 0) {
		cout << "\nKhong tim thay cau thu trong danh sach" << endl;
	}
}
void Capnhatthedo(DSCT &dsct, char *ten, int sothedomoi) {
	int found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].Hoten, ten) == 0 || strcmp(dsct.ds[i].mact, ten) == 0) {
			dsct.ds[i].thedo += sothedomoi;
			found = 1;
			break;
		}
	}
	if (found == 0) {
		cout << "\nKhong tim thay cau thu trong danh sach" << endl;
	}
}
void Capnhatthevang(DSCT &dsct, char *ten, int sothevangmoi) {
	int found = 0;
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (strcmp(dsct.ds[i].Hoten, ten) == 0 || strcmp(dsct.ds[i].mact, ten) == 0) {
			dsct.ds[i].thevang += sothevangmoi;
			found = 1;
			break;
		}
	}
	if (found == 0) {
		cout << "\nKhong tim thay cau thu trong danh sach" << endl;
	}
}
void dsCauthubicamthidau(DSCT dsct) {
	cout << "\nDanh sach cau thu bi cam thi dau:\n";
	for (int i= 0; i < dsct.soluong; i++)
	{
		if (dsct.ds[i].thevang == 3 || dsct.ds[i].thedo == 1) {
			cout << "Ma CT: " << dsct.ds[i].mact << ", Ho ten: " << dsct.ds[i].Hoten << ", So ao: " << dsct.ds[i].Soao << endl;
		}
	}
}
void dsCauthuduocphepthidau(DSCT dsct) {
	cout << "\nDanh sach cau thu duoc phep thi dau\n";
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (dsct.ds[i].thevang < 3 && dsct.ds[i].thedo < 1) {	
			cout << "Ma CT: " << dsct.ds[i].mact << ", Ho ten: " << dsct.ds[i].Hoten << ", So ao: " << dsct.ds[i].Soao << endl;
		}
	}
}
void dscauthuchuacobanthang(DSCT dsct) {
	cout << "\nDanh sach cau thu chua co ban thang\n";
	for (int i = 0; i < dsct.soluong; i++)
	{
		if (dsct.ds[i].sobanthang == 0) {
			cout << "Ma CT: " << dsct.ds[i].mact << ", Ho ten: " << dsct.ds[i].Hoten << ", So ao: " << dsct.ds[i].Soao << endl;
		}
	}
}
void sapxepdscauthutheotenaz(DSCT &dsct) {
	CauThu ct;
	for (int i = 0; i < dsct.soluong - 1; i++)
	{
		for (int j = i + 1; j < dsct.soluong; j++)
		{
			if (strcmp(dsct.ds[j].Hoten, dsct.ds[i].Hoten) < 0) {
				ct = dsct.ds[i];
				dsct.ds[i] = dsct.ds[j];
				dsct.ds[j] = ct;
			}
		}
	}
}
void sapxepdscauthutheotenza(DSCT &dsct) {
	CauThu ct;
	for (int i = 0; i < dsct.soluong - 1; i++)
	{
		for (int j = i + 1; j < dsct.soluong; j++)
		{
			if (strcmp(dsct.ds[j].Hoten, dsct.ds[i].Hoten) > 0) {
				ct = dsct.ds[i];
				dsct.ds[i] = dsct.ds[j];
				dsct.ds[j] = ct;
			}
		}
	}
}
void SapXepTheoBanThang(DSCT &dsct) {
	for (int i = 0; i < dsct.soluong - 1; i++) {
		for (int j = i + 1; j < dsct.soluong; j++) {
			if (dsct.ds[j].sobanthang > dsct.ds[i].sobanthang) {
				swap(dsct.ds[i], dsct.ds[j]);
			}
		}
	}
}
void XuatBangXepHang(DSCT &dsct) {
	cout << "Bang xep hang cac cau thu ghi ban nhieu nhat\n";
	SapXepTheoBanThang(dsct);
	for (int i = 0; i < dsct.soluong; i++) {
		cout << "Hang " << i + 1 << ": ";
		cout << "Ma CT: " << dsct.ds[i].mact << ", Ho ten: " << dsct.ds[i].Hoten << ", So ao: " << dsct.ds[i].Soao << endl;
	}
}
void menuCapnhat(DSCT &ds,char* ma) {
	int luaChon, sobanthangmoi, sothevangmoi, sothedomoi;
	CT ct;
	do {
		cout << "\n======= Menu Cap Nhat =======" << endl;
		cout << "1. Cap nhat ten." << endl;
		cout << "2. Cap nhat quoc tich." << endl;
		cout << "3. Cap nhat so ao." << endl;
		cout << "4. Cap nhat ban thang." << endl;
		cout << "5. Cap nhat the vang." << endl;
		cout << "6. Cap nhat the do." << endl;
		cout << "7. Tro ve menu chinh." << endl;
		cout << "=============================" << endl;
		cout << "Chon thong tin ban muon cap nhat: ";
		cin >> luaChon;
		switch (luaChon) {
		case 1:
			cout << "\nNhap ma cau thu can sua ten: ";
			cin >> ct.mact;
			CapNhatTen(ds, ct.mact);
			cout << "\nDanh sach cau thu sau khi cap nhat !";
			XuatDSCT(ds);
			break;
		case 2:
			cout << "\nNhap ma cau thu can sua quoc tich: ";
			cin >> ct.mact;
			CapNhatQuoctich(ds, ct.mact);
			cout << "\nDanh sach cau thu sau khi cap nhat !";
			XuatDSCT(ds);
			break;
		case 3:
			cout << "\nNhap ma cau thu can sua so ao: ";
			cin >> ct.mact;
			CapNhatSoao(ds, ct.mact);
			cout << "\nDanh sach cau thu sau khi cap nhat !";
			XuatDSCT(ds);
			break;
		case 4:
			cout << "\nNhap ma cau thu hoac ten cau thu: ";
			cin >> ct.Hoten;
			cout << "\nNhap so ban thang moi: ";
			cin >> sobanthangmoi;
			if (sobanthangmoi >= 0) {
				Capnhatbanthang(ds, ct.Hoten, sobanthangmoi);
				cout << "\nCap nhat thanh cong.";
				XuatDSCT(ds);
			}
			else {
				cout << "\nSo ban thang nhap vao khong hop le.";
				XuatDSCT(ds);
			}
			break;
		case 5:
			cout << "\nNhap ma cau thu hoac ten cau thu: ";
			cin >> ct.Hoten;
			cout << "\nNhap so the vang moi: ";
			cin >> sothevangmoi;
			Capnhatthevang(ds, ct.Hoten, sothevangmoi);
			cout << "\nCap nhat thanh cong";
			XuatDSCT(ds);
			break;
		case 6:
			cout << "\nNhap ma cau thu hoac ten cau thu: ";
			cin >> ct.Hoten;
			cout << "\nNhap so the do moi: ";
			cin >> sothedomoi;
			Capnhatthedo(ds, ct.Hoten, sothedomoi);
			cout << "\nCap nhat thanh cong";
			XuatDSCT(ds);
			break;
		case 7:
			cout << "\nTro ve menu chinh.";
			break;
		default:
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
		}

	} while (luaChon != 7);
}
void menuHienthi(DSCT &ds) {
	int choice;
	do {
		cout << "\n======= Menu Hien Thi ====================" << endl;
		cout << "1. Hien thi danh sach cau thu tu A-Z" << endl;
		cout << "2. Hien thi danh sach cau thu tu Z-A" << endl;
		cout << "3. Hien thi danh sach cau thu duoc phep thi dau" << endl;
		cout << "4. Hien thi danh sach cau thu bi cam thi dau" << endl;
		cout << "5. Hien thi danh sach cau thu chua co ban thang" << endl;
		cout << "6. Tro ve menu chinh." << endl;
		cout << "==============================================" << endl;
		cout << "Chon che do ban muon hien thi: ";
		cin >> choice;
		switch (choice) {
		case 1:
			sapxepdscauthutheotenaz(ds);
			XuatDSCT(ds);
			break;
		case 2:
			sapxepdscauthutheotenza(ds);
			XuatDSCT(ds);
			break;
		case 3:
			dsCauthuduocphepthidau(ds);
			break;
		case 4:
			dsCauthubicamthidau(ds);
			break;
		case 5:
			dscauthuchuacobanthang(ds);
			break;
		case 6:
			cout << "Tro ve menu chinh";
			break;
		default:
			cout << "Chuc nang khong ton tai. Vui long thu lai";
			break;
		}
	} while (choice != 6);
}
void LuuDSCT(DSCT &l) {
	FILE *f;
	fopen_s(&f, "dsct.txt", "w");
	if (f == NULL) {
		cout << "Loi luu File!";
		return;
	}
	else {
		cout << "\nLuu file thanh cong";
	}
	fprintf(f, "%d", l.soluong);
	for (int i = 0; i < l.soluong; i++)
	{
		fprintf_s(f, "\n");
		fprintf_s(f, "%-13s", l.ds[i].mact);
		fprintf_s(f, "%-24s", l.ds[i].Hoten);
		fprintf_s(f, "%-15s", l.ds[i].Quoctich);
		fprintf_s(f, "%-10d", l.ds[i].Soao);
		fprintf_s(f, "%-10d", l.ds[i].sobanthang);
		fprintf_s(f, "%-10d", l.ds[i].thevang);
		fprintf_s(f, "%d", l.ds[i].thedo);
	}
	fclose(f);
}
void MoDSCT(DSCT &l) {
	FILE *f; int ch;
	fopen_s(&f,"dsct.txt","r");
	if (f == NULL) {
		cout << "Loi mo file!!";
		return;
	}
	else {
		cout << "\nMo file thanh cong";
	}
	fscanf_s(f, "%d", &l.soluong);
	for (int i = 0;i < l.soluong;i++)
	{
		ch = fgetc(f);
		fscanf_s(f, "%13s", l.ds[i].mact, _countof(l.ds[i].mact));
		fscanf_s(f, "%24s", l.ds[i].Hoten, _countof(l.ds[i].Hoten));
		fscanf_s(f, "%15s", l.ds[i].Quoctich, _countof(l.ds[i].Quoctich));
		fscanf_s(f, "%10d", &l.ds[i].Soao);
		fscanf_s(f, "%10d", &l.ds[i].sobanthang);
		fscanf_s(f, "%10d", &l.ds[i].thevang);
		fscanf_s(f, "%d", &l.ds[i].thedo);
	}
	fclose(f);
}