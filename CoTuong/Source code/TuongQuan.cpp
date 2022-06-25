#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <iostream>
using namespace std;
TuongQuan::TuongQuan()
{
}
TuongQuan::TuongQuan(int x, int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
TuongQuan::~TuongQuan()
{
}
void TuongQuan::Ve()
{
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	float r = BanKinh * 0.5;
	COLORREF COLOR;

	Create(x, y, z, COLOR);
	// Vẽ đương cong C
	HalfCircle(r, x + 0.1 * BanKinh, y, COLOR, 0);
	HalfCircle(r - 1, x + 0.1 * BanKinh, y, COLOR, 0);
	HalfCircle(r + 1, x + 0.1 * BanKinh, y, COLOR, 0);
	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void TuongQuan::DiChuyen()
{
	cout << "Di tung o mot, di ngang hoac doc." << endl;
	cout << "Tuong luon luon phai o trong pham vi cung va khong duoc ra ngoai cung." << endl;
	// Khái báo mảng để chứa các tọa độ mà con Tướng có thể đi
	int xx[4] = { -1,-1,-1,-1 };
	int yy[4] = { -1,-1,-1,-1 };
	xx[0] = this->x; yy[0] = this->y - 1;
	xx[1] = this->x; yy[1] = this->y + 1;
	xx[2] = this->x - 1; yy[2] = this->y;
	xx[3] = this->x + 1; yy[3] = this->y;
	cout << "Cac toa do con Tuong Quan co the di:\n";
	for (int i = 0; i < 4; ++i)
	{
		if (IsOk(xx[i], yy[i], this->z))
		{
			cout << "( " << xx[i] + 1 << ", " << yy[i] + 1 << " )\n";
		}
		else
		{
			xx[i] = -1;
			yy[i] = -1;
		}
	}
	int iTempX, iTempY;
	bool duoc = 0;
	while (!duoc)
	{
		cout << "Nhap toa doa can di x y (-1 de thoat): ";
		NhapViTriDiChuyen(iTempX, iTempY);
		if (iTempX == -2) break;

		// Xem nhập có đúng cú pháp không?
		if (x < 0 || y < 0 || x > 8 || y > 9)
		{

			cout << "Vui long nhap lai.\n";
			continue;
		}

		// Tìm xem tọa độ vừa nhập có đi được không?
		for (int i = 0; i < 3; ++i)
		{
			if (xx[i] == iTempX && yy[i] == iTempY)
			{
				duoc = 1;
				break;
			}	
			if (duoc) break;
		}
		// Nếu nhập đúng vị trí thì cho quân cờ di chuyển và ngược lại
		if (duoc)
		{
			XoaConCo(this->x, this->y);
			Update(this->x, this->y, iTempX, iTempY);
			this->x = iTempX;
			this->y = iTempY;
			this->Ve();
		}
		else
		{
			cout << "Vui long nhap lai.\n";
		}
	}
}