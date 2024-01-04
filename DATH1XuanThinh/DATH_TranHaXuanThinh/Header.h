#include <iostream>
#include <iomanip>
#include <string>
const int N = 100;
using namespace std;

typedef struct CauThu
{
	char mact[10];
	char Hoten[30];
	char Quoctich[15];
	int Soao;
	int sobanthang;
	int thevang;
	int thedo;
}CT;
struct DSCT {
	int soluong;
	CT ds[N];
};
void NhapCauThu(CT &ct);
void XuatCauThu(CT ct);
void NhapDSCT(DSCT &ct);
void XuatDSCT(DSCT l);
bool Kiemtramact(DSCT &dsct, char* ma);
bool kiemtra(const char mact[]);
void them_cauthu(DSCT &dsct, CauThu ct);
void xoa_cauthu(DSCT &dsct,char* ma,char* ten);
void tim_kiem(DSCT &dsct, char* ma);
void Nameupdate(CT &ct);
void CapNhatTen(DSCT &dsct, char* ma);
void QuoctichUpdate(CT &ct);
void CapNhatQuoctich(DSCT &dsct, char* ma);
void SoaoUpdate(CT &ct);
void CapNhatSoao(DSCT &dsct, char* ma);
void Capnhatbanthang(DSCT &dsct, char *ten, int sobanthangmoi);
void Capnhatthevang(DSCT &dsct, char *ten, int sothevangmoi);
void Capnhatthedo(DSCT &dsct, char *ten, int sothedomoi);
void dsCauthubicamthidau(DSCT dsct);
void dsCauthuduocphepthidau(DSCT dsct);
void dscauthuchuacobanthang(DSCT dsct);
void sapxepdscauthutheotenaz(DSCT &dsct);
void sapxepdscauthutheotenza(DSCT &dsct);
void SapXepTheoBanThang(DSCT &dsct);
void XuatBangXepHang(DSCT &dsct);
void menuCapnhat(DSCT &ds, char* ma);
void menuHienthi(DSCT &ds);
void LuuDSCT(DSCT &l);
void MoDSCT(DSCT &l);