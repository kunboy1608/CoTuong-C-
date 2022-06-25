#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <iostream>
using namespace std;
Sy::Sy()
{
}
Sy::Sy(int x, int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Sy::~Sy()
{
}
void Sy::Ve()
{
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	float r = BanKinh * 0.3;
	COLORREF COLOR;

	Create(x, y, z, COLOR);
	// Vẽ đường cong trên
	HalfCircle(r, x, y - 0.3 * BanKinh, COLOR, 0);
	HalfCircle(r - 1, x, y - 0.3 * BanKinh, COLOR, 0);
	HalfCircle(r + 1, x, y - 0.3 * BanKinh, COLOR, 0);
	//Vẽ đường cong dưới
	HalfCircle(r, x, y + 0.3 * BanKinh, COLOR, 1);
	HalfCircle(r - 1, x, y + 0.3 * BanKinh, COLOR, 1);
	HalfCircle(r + 1, x, y + 0.3 * BanKinh, COLOR, 1);
	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void Sy::DiChuyen()
{
	cout << "Di xeo 1 o moi nuoc." << endl;
	cout << "Si luon luon phai o trong cung nhu tuong." << endl << endl;
	int xx[4] = { -1,-1,-1,-1 };
	int yy[4] = { -1,-1,-1,-1 };
	int index = 0;
	switch (this->x)
	{
	// Xét trường hợp con Sỹ ở tọa độ x == 3 (bên trái cung)
	case 3:
		if (this->y == 0 || this->y == 7)
		{
			xx[index] = this->x + 1;
			yy[index] = this->y + 1;
			++index;
		}
		else if (this->y == 2 || this->y == 9)
		{
			xx[index] = this->x + 1;
			yy[index] = this->y - 1;
			++index;
		}
		break;
	// Xét trường hợp con Sỹ ở tọa độ x == 4 (trung tâm cung)
	case 4:
		if (y == 1)
		{
			xx[index] = 3;
			yy[index] = 0;
			++index;
			xx[index] = 5;
			yy[index] = 0;
			++index;
			xx[index] = 3;
			yy[index] = 2;
			++index;
			xx[index] = 5;
			yy[index] = 2;
			++index;
		}
		else if (y == 8)
		{
			cout << "( 3, 9)\n";
			xx[index] = 3;
			yy[index] = 9;
			++index;
			cout << "( 5, 9)\n";
			xx[index] = 5;
			yy[index] = 9;
			++index;
			cout << "( 3, 7)\n";
			xx[index] = 3;
			yy[index] = 7;
			++index;
			cout << "( 5, 7)\n";
			xx[index] = 5;
			yy[index] = 7;
			++index;
		}
		break;
	// Xét trường hợp con Sỹ ở tọa độ x == 3 (bên phải cung)
	case 5:
		if (this->x == 0 || this->x == 7)
		{
			cout << "( " << this->x - 1 << ", " << this->y + 1 << " )" << endl;
			xx[index] = this->x - 1;
			yy[index] = this->y + 1;
			++index;
		}
		else if (this->x == 2 || this->x == 9)
		{
			cout << "( " << this->x - 1 << ", " << this->y - 1 << " )" << endl;
			xx[index] = this->x - 1;
			yy[index] = this->y - 1;
			++index;
		}
		break;
	default:
		break;
	}
	cout << "Cac toa do con Sy co the di:\n";
	for (int i = 0; i < 3; ++i)
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

		// Tim xem toa do vua nhap co thoa man khong
		for (int i = 0; i < 4; ++i)
		{
			if (xx[i] == iTempX && yy[i] == iTempY)
			{
				duoc = 1;
				break;
			}
			if (duoc) break;
		}
		// Neu nhap dung vi tri co the di chuyen thi di chuyen con co
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