#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <iostream>
using namespace std; 
Ma::Ma()
{
}
Ma::Ma(int x,int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Ma::~Ma()
{
}
void Ma::Ve()
{
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	COLORREF COLOR;
	Create(x, y, z, COLOR);

	// Vẽ nét  "/"
	Line(x, y, x + 0.5 * BanKinh, y - 0.5 * BanKinh, COLOR);
	Line(x - 1, y - 1, x + 0.5 * BanKinh - 1, y - 0.5 * BanKinh - 1, COLOR);
	Line(x + 1, y + 1, x + 0.5 * BanKinh + 1, y - 0.5 * BanKinh + 1, COLOR);
	// Vẽ nét  "\"
	Line(x, y, x - 0.5 * BanKinh, y - 0.5 * BanKinh, COLOR);
	Line(x, y - 1, x - 0.5 * BanKinh, y - 0.5 * BanKinh - 1, COLOR);
	Line(x, y + 1, x - 0.5 * BanKinh, y - 0.5 * BanKinh + 1, COLOR);
	// Vẽ nét thằng bên trái
	Line(x - 0.5 * BanKinh, y - 0.6 * BanKinh, x - 0.5 * BanKinh, y + 0.6 * BanKinh, COLOR);
	Line(x - 0.5 * BanKinh + 1, y - 0.6 * BanKinh, x - 0.5 * BanKinh + 1, y + 0.6 * BanKinh, COLOR);
	Line(x - 0.5 * BanKinh + 2, y - 0.6 * BanKinh, x - 0.5 * BanKinh + 2, y + 0.6 * BanKinh, COLOR);
	// Vẽ nét thằng bên phải
	Line(x + 0.5 * BanKinh, y - 0.6 * BanKinh, x + 0.5 * BanKinh, y + 0.6 * BanKinh, COLOR);
	Line(x + 0.5 * BanKinh - 1, y - 0.6 * BanKinh, x + 0.5 * BanKinh - 1, y + 0.6 * BanKinh, COLOR);
	Line(x + 0.5 * BanKinh - 2, y - 0.6 * BanKinh, x + 0.5 * BanKinh - 2, y + 0.6 * BanKinh, COLOR);

	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void Ma::DiChuyen()
{
	cout << "Di ngang 2 o va doc 1 o (hay doc 2 o ngang 1 o) cho moi nuoc di." << endl;
	cout << "Neu co quan nam ngay ben canh ma va can duong\nngang 2 (hay duong doc 2), ma bi can khong duoc di duong do." << endl << endl;

	// Khai báo mảng để chứa tọa độ mà con Mã có thể đi vì con Mã có thể chọn tối đa 1 trong 8 ô cho một lần đi
	int xx[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
	int yy[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };

	// Xét trường hợp con Mã có bị chặn không
	if (!IsChan(x - 1, y))
	{
		xx[0] = x - 2; yy[0] = y - 1;
		xx[1] = x - 2; yy[1] = y + 1;
	}
	// Xét trường hợp con Mã có bị chặn không
	if (!IsChan(x + 1, y))
	{
		xx[2] = x + 2; yy[2] = y - 1;
		xx[3] = x + 2; yy[3] = y + 1;
	}
	// Xét trường hợp con Mã có bị chặn không
	if (!IsChan(x, y - 1))
	{
		yy[4] = y - 2; xx[4] = x - 1;
		yy[5] = y - 2; xx[5] = x + 1;
	}
	// Xét trường hợp con Mã có bị chặn không
	if (!IsChan(x, y + 1))
	{
		yy[6] = y + 2; xx[6] = x - 1;
		yy[7] = y + 2; xx[7] = x + 1;
	}
	// Kiểm tra lại và in ra những tọa đọ con Mã có thê đi
	cout << "Cac toa con ma co the di: \n";
	for (int i = 0; i < 8; ++i)
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
	int iTempX, iTempY; // Khai báo các tọa độ tạm thời để nhập
	bool duoc = 0; // Biến để xét xem nhập đúng tọa độ có đi được không
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
		for (int i = 0; i < 8; ++i)
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