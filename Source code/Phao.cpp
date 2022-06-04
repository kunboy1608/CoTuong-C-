#include "Header.h"
#include "GraphcsPro.h"
#include "Draw.h"
#include <vector>
#include <iostream>
using namespace std;
Phao::Phao()
{

}
Phao::Phao(int x, int y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Phao::~Phao()
{

}
void Phao::Ve()
{
	// Khai báo biến tạm để không thay đổi vị trí quân cờ
	int xx = x;
	int yy = y;
	bool zz = z;
	VeNen(x, y);
	COLORREF COLOR;
	Create(x, y, z, COLOR);
	float r = BanKinh * 0.4;
	// Vẽ đường thẳng
	Line(x - 0.1 * BanKinh, y + 0.6 * BanKinh, x - 0.1 * BanKinh, y - 0.6 * BanKinh, COLOR);
	Line(x - 0.1 * BanKinh + 1, y + 0.6 * BanKinh, x - 0.1 * BanKinh + 1, y - 0.6 * BanKinh, COLOR);
	Line(x - 0.1 * BanKinh - 1, y + 0.6 * BanKinh, x - 0.1 * BanKinh - 1, y - 0.6 * BanKinh, COLOR);
	// Vẽ nửa hình tròn
	HalfCircle(r, x - 0.1 * BanKinh, y - BanKinh * 0.2, COLOR, 1);
	HalfCircle(r + 1, x - 0.1 * BanKinh, y - BanKinh * 0.2, COLOR, 1);
	HalfCircle(r + 2, x - 0.1 * BanKinh, y - BanKinh * 0.2, COLOR, 1);

	// Trả về gia trị bạn đầu cho quân cờ
	x = xx;
	y = yy;
	z = zz;
}
void Phao::DiChuyen()
{
	cout << "Di ngang va doc giong nhu xe." << endl;
	cout << "Diem khac biet la neu phao muon an quan, phao phai nhay qua dung 1 quan nao do." << endl;
	cout << "Khi khong an quan, tat ca cac diem tu cho di den \ncho den phai khong co quan can duong." << endl << endl;
	cout << "Cac buoc con Phao co the di chuyen:\n";
	/// Tim cac o phia tren con Phao co the di
	int xx[17] = { -1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1 };
	int yy[17] = { -1,-1,-1,-1,-1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1 };
	int index = 0;

	/// Tim cac o phia tren con Phao co the di
	for (int i = this->y - 1; i >= 0; --i)
	{
		if (IsOk(x, i, this->z) && !(IsChan(x, i)))
		{
			cout << "( " << this->x + 1 << ", " << i + 1 << " )" << endl;
			xx[index] = this->x;
			yy[index] = i;
			++index;
		}
		else if (IsChan(x, i))
		{
			for (int j = i - 1; j >=0; --j)
			{
				if (IsOk(x, j, this->z) && IsChan(x, j))
				{
					cout << "( " << this->x + 1 << ", " << j + 1 << " )" << endl;
					xx[index] = this->x;
					yy[index] = j;
					++index;
					break;
				}
			}
			break;
		}
	}
	/// Tim cac o phia duoi con Phao co the di
	for (int i = this->y + 1; i < 10; ++i)
	{
		if (IsOk(x, i, this->z) && !(IsChan(x, i)))
		{
			cout << "( " << this->x + 1 << ", " << i + 1<< " )" << endl;
			xx[index] = this->x;
			yy[index] = i;
			++index;
		}
		else if (IsChan(x, i))
		{
			for (int j = i + 1; j < 10; ++j)
			{
				if (IsOk(x, j, this->z) && (IsChan(x, j)))
				{
					cout << "( " << this->x + 1 << ", " << j + 1 << " )" << endl;
					xx[index] = this->x;
					yy[index] = j;
					++index;
					break;
				}
			}
			break;
		}
	}
	// Tim cac o phai ben trai con Phao co the di chuyen
	for (int i = this->x - 1; i >= 0; --i)
	{
		if (IsOk(i, y, this->z) && !(IsChan(i, y)))
		{
			cout << "( " << i + 1 << ", " << this->y + 1 << " )" << endl;
			xx[index] = i;
			yy[index] = this->y;
			++index;
		}
		else if (IsChan(i, y))
		{
			for (int j = i - 1; j >=0; --j)
			{
				if (IsOk(j, y, this->z) && (IsChan(j, y)))
				{
					cout << "( " << j + 1 << ", " << this->y + 1 << " )" << endl;
					xx[index] = j;
					yy[index] = this->y;
					++index;
					break;
				}
			}
			break;
		}
	}
	/// Tim cac o phia ban  con Phao co the di
	for (int i = this->x + 1; i < 10; ++i)
	{
		if (IsOk(i, y, this->z) && !(IsChan(i, y)))
		{
			cout << "( " << i + 1 << ", " << this->y + 1 << " )" << endl;
			xx[index] = i;
			yy[index] = this->y;
			++index;
		}
		else if (IsChan(i, y))
		{
			for (int j = i + 1; j < 9; ++j)
			{
				if (IsOk(j, y, this->z) && (IsChan(j, y)))
				{
					cout << "( " << j + 1 << ", " << this->y + 1<< " )" << endl;
					xx[index] = j;
					yy[index] = this->y;
					break;
				}
			}
			break;
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
		for (int i = 0; i < 17; ++i)
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
