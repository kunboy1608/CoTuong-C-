#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <iostream>
using namespace std;
Tuong::Tuong()
{

}
Tuong::Tuong(int x, int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Tuong::~Tuong()
{

}
void Tuong::Ve()
{
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	COLORREF COLOR;
	Create(x, y, z, COLOR);
	// Vẽ đường thằng
	Line(x, y + 0.6 * BanKinh, x, y - 0.6 * BanKinh, COLOR);
	Line(x + 1, y + 0.6 * BanKinh, x + 1, y - 0.6 * BanKinh, COLOR);
	Line(x - 1, y + 0.6 * BanKinh, x - 1, y - 0.6 * BanKinh, COLOR);

	// Vẽ đường ngang
	Line(x - 0.5 * BanKinh, y - 0.6 * BanKinh, x + 0.5 * BanKinh, y - 0.6 * BanKinh, COLOR);
	Line(x - 0.5 * BanKinh, y - 0.6 * BanKinh + 1, x + 0.5 * BanKinh, y - 0.6 * BanKinh + 1, COLOR);
	Line(x - 0.5 * BanKinh, y - 0.6 * BanKinh + 2, x + 0.5 * BanKinh, y - 0.6 * BanKinh + 2, COLOR);
	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void Tuong::DiChuyen()
{
	cout << "Di cheo 2 o (ngang 2 va doc 2) cho moi nuoc di." << endl;
	cout << "Tuong chi duoc phep o mot ben cua ban co,\nkhong duoc di chuyen sang nua ban co cua doi phuong." << endl;
	cout << "Nuoc di cua quan tuong se khong hop le khi\nco mot quan co nam chan giua tuong di." << endl << endl;
	// Khởi tọa mang chứa tọa độ con Tượng có thể đi. Vì con Tượng có tối đa 4 vị trí có thể đi
	int xx[4] = { -1,-1,-1,-1 };
	int yy[4] = { -1,-1,-1,-1 };
	xx[0] = this->x - 2; yy[0] = this->y - 2;
	xx[1] = this->x - 2; yy[1] = this->y + 2;
	xx[2] = this->x + 2; yy[2] = this->y + 2;
	xx[3] = this->x + 2; yy[3] = this->y - 2;
	cout << "Cac toa do con Tuong co the di:\n";
	for (int i = 0; i < 4; ++i)
	{
		if (IsOk(xx[i], yy[i], this->z))
		{
			cout << "( " << xx[i] + 1 << ", " << yy[i] + 1<< " )\n";
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
		for (int i = 0; i < 4; ++i)
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