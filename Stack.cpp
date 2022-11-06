#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

// ----------------------------Bệnh nhân------------------------------------
struct benhnhan
{
    int maBN;
    string tenBN;
    string gt;
};
struct nodeBn
{
    benhnhan bn;
    struct nodeBn *pNext;
};
void nhapbn(benhnhan &x)
{
    cin.ignore();
    cout << "\nNhap ten: ";
    getline(cin, x.tenBN);
    cout << "\nNhap ma: ";
    cin >> x.maBN;
    cin.ignore();
    cout << "\nNhap gioi tinh: ";
    getline(cin, x.gt);
}
void hienbn(benhnhan x)
{
    cout << "\n Ten benh nhan : " << x.tenBN;
    cout << "\n Ma so benh nhan : " << x.maBN;
    cout << "\n Gioi tinh: " << x.gt;
}

// -----------------------------Bác sỹ------------------------------
struct BacSy
{
    int ma;
    string name;
    string ngaysinh;
    string gt;
};
struct nodeBS
{
    BacSy bs;
    struct nodeBS *pNext;
};

void nhapBS(BacSy &x)
{
    cout << "\nNhap ten: ";
    getline(cin, x.name);
    cout << "\nNhap ma: ";
    cin >> x.ma;
    cin.ignore();
    cout << "\nNhap ngay sinh : ";
    getline(cin, x.ngaysinh);
    cout << "\nNhap gioi tinh : ";
    getline(cin, x.gt);
}
void inBS(BacSy x)
{
    cout << "\n Ten bac sy : " << x.name;
    cout << "\n Ma bac sy : " << x.ma;
    cout << "\n ngay sinh bac sy : " << x.ngaysinh;
    cout << "\n gioi tinh  : " << x.gt;
}

// ----------------------------Phòng khám-----------------------------
struct phongkham
{
    string tenPK;
    int maPK;
};

struct nodePhongKham
{
    phongkham pk;
    struct nodePhongKham *pNext;
};
struct stackPK
{
    nodePhongKham *pTop;
};
void KhoiTaoStackPK(stackPK &l)
{
    l.pTop = NULL;
}
nodePhongKham *khoiTaoNodePK(phongkham x)
{
    nodePhongKham *p = new nodePhongKham;
    if (p == NULL)
    {
        cout << "\n Het bo nho!";
        return NULL;
    }
    p->pk = x;
    p->pNext = NULL;
    return p;
}
void nhapPK(phongkham &x)
{
    cin.ignore();
    cout << "\n Nhap ten: ";
    getline(cin, x.tenPK);
    cout << "\n Nhap ma PK: ";
    cin >> x.maPK;
}
void table()
{
    cout << "\n"
         << setw(16) << "Ten phong kham ";
    cout << setw(16) << "Ma phong kham";
}
void inPK(phongkham x)
{
    cout << "\n"
         << setw(16) << x.tenPK;
    cout << setw(16) << x.maPK;
}
bool IsEmpty(stackPK s)
{
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
}
// Hàm thêm 1 phần tử vào stack
bool Push(stackPK &s, nodePhongKham *p)
{
    if (p == NULL)
    {
        return false;
    }
    if (IsEmpty(s) == true)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}

// Hàm lấy ra 1 phần tử đầu xem và hủy nó đi
bool Pop(stackPK &s, phongkham &pk)
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    else
    {
        nodePhongKham *p = s.pTop;
        pk = p->pk;
        s.pTop = s.pTop->pNext;
        // delete p;
    }
    return true;
}
// Hàm chỉ hiện ra xem và không xóa nó đi
bool Top(stackPK &s, phongkham &pk)
{
    if (IsEmpty(s) == true)
    {
        return false;
    }
    pk = s.pTop->pk;
    return true;
}

void nhapDSPhongKham(stackPK &pk)
{
    int n;
    cout << "\nNhap so luong phong kham : ";
    cin >> n;
    phongkham p;
    nodePhongKham *node;
    for (int i = 0; i < n; i++)
    {
        nhapPK(p);
        node = khoiTaoNodePK(p);
        Push(pk, node);
    }
}

void hienDSPhongKham(stackPK s)
{
    table();
    while (IsEmpty(s) == false)
    {
        phongkham p;
        Pop(s, p);
        inPK(p);
    }
}

struct date
{
    int day;
    int month;
    int year;
};
struct phieukham
{
    date ngay;
    int maPh;
    benhnhan bn;
    BacSy bs;
    stackPK dspk;
    string chandoan;
    float vienphi;
};

struct nodePhieuKham
{
    phieukham pk;
    struct nodePhieuKham *pNext;
};

struct stackPhieuKham
{
    nodePhieuKham *pTop;
};

void khoitaoStackPhieuKham(stackPhieuKham &s)
{
    s.pTop = NULL;
}

nodePhieuKham *khoitaoNode_PhieuKham(phieukham &p)
{
    nodePhieuKham *x = new nodePhieuKham;
    if (x == NULL)
    {
        cout << "\n K du bo nho";
        return NULL;
    }
    x->pk = p;
    x->pNext = NULL;
    return x;
}

void nhapPhieu(phieukham &x)
{
    cout << "\nNhap ngay : ";
    cin >> x.ngay.day;
    cout << "\nNhap thang : ";
    cin >> x.ngay.month;
    cout << "\nNhap nam : ";
    cin >> x.ngay.year;
    cout << "\nNhap ma phieu : ";
    cin >> x.maPh;
    cout << "\n\tNhap benh nhan : ";
    nhapbn(x.bn);
    cout << "\n\tNhap bac sy kham : ";
    nhapBS(x.bs);
    cout << "\n\tNhap danh sach phong kham : ";
    KhoiTaoStackPK(x.dspk);
    nhapDSPhongKham(x.dspk);
    cout << "Chan doan sau cung cua bac sy  : ";
    cin >> x.chandoan;
    cout << "\n----->vien phi can tra : ";
    cin.ignore();
    cin >> x.vienphi;
}

void hienPhieu(phieukham x)
{
    cout << "\n Date " << x.ngay.day << "/" << x.ngay.month << "/" << x.ngay.year;
    cout << "\n Ma phieu : " << x.maPh;
    cout << "\n\t Thong tin bac si kham ";
    inBS(x.bs);
    cout << "\n\t Thong tin benh nhan ";
    hienbn(x.bn);
    cout << "\n\t Thong tin cac phong kham ";
    hienDSPhongKham(x.dspk);
    cout << "\n ------>chan doan : " << x.chandoan;
    cout << "\n ------>vien phi : " << x.vienphi;
}

bool IsEmptyPhieuKham(stackPhieuKham &s)
{
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
}
bool PushPhieuKham(stackPhieuKham &s, nodePhieuKham *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (IsEmptyPhieuKham(s) == true)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}
bool PopPhieuKham(stackPhieuKham &s, phieukham &pk)
{
    if (IsEmptyPhieuKham(s) == true)
    {
        return false;
    }
    else
    {
        nodePhieuKham *p = s.pTop;
        pk = p->pk;
        s.pTop = s.pTop->pNext;
        // delete p;
    }
    return true;
}

void nhapDSPhieu(stackPhieuKham &s)
{
    cout << "\n Moi nhap so luong can them : ";
    int n;
    cin >> n;
    phieukham pk;
    nodePhieuKham *p;
    for (int i = 0; i < n; i++)
    {
        cout << "\n ---------------Nhap phieu thu : " << i + 1 << "--------------";
        nhapPhieu(pk);
        p = khoitaoNode_PhieuKham(pk);
        PushPhieuKham(s, p);
    }
}

void hienDSPhieu(stackPhieuKham s)
{
    while (IsEmptyPhieuKham(s) == false)
    {
        phieukham x;
        PopPhieuKham(s, x);
        hienPhieu(x);
        cout << "\n\t\t*---------------------------------*\n";
    }
    // for (nodePhieuKham *p = s.pTop; p != NULL; p = p->pNext)
    // {
    //     hienPhieu(p->pk);
    //     cout << "\n\t\t*---------------------------------*\n";
    // }
}

void ghiFilePhieuKham(stackPhieuKham &s)
{
    fstream f;
    f.open("PhieukhamStack.dat", ios::out | ios::binary);
    for (nodePhieuKham *p = s.pTop; p != NULL; p = p->pNext)
    {
        f.write((char *)&(p->pk), sizeof(phieukham));
    }
    f.close();
    cout << "\n Ghi file thanh cong !";
}
void docFilePhieuKham(stackPhieuKham &s)
{
    ifstream f;
    f.open("PhieukhamStack.dat", ios::in | ios::binary);
    phieukham pk;
    nodePhieuKham *p;
    khoitaoStackPhieuKham(s);
    while (f.read((char *)&pk, sizeof(phieukham)))
    {
        p = khoitaoNode_PhieuKham(pk);
        PushPhieuKham(s, p);
    }
    f.close();
    cout << "Doc file thanh cong !";
    hienDSPhieu(s);
}
void them1PhieuKhamvaodauDS(stackPhieuKham &s)
{
    phieukham pk;
    nodePhieuKham *p;
    cout << "\n----Moi nhap phieu kham can them----\n ";
    nhapPhieu(pk);
    p = khoitaoNode_PhieuKham(pk);
    PushPhieuKham(s, p);
}
float vienphi_Min(stackPhieuKham s)
{
    float min = s.pTop->pk.vienphi;
    for (nodePhieuKham *p = s.pTop->pNext; p != NULL; p = p->pNext)
    {
        if (p->pk.vienphi < min)
        {
            min = p->pk.vienphi;
        }
    }
    return min;
}
void timkiemPhieuKham_Min(stackPhieuKham s)
{

    for (nodePhieuKham *p = s.pTop; p != NULL; p = p->pNext)
    {
        if (p->pk.vienphi == vienphi_Min(s))
        {
            hienPhieu(p->pk);
        }
    }
}
void themsauPhieuMin(stackPhieuKham &s)
{
    phieukham pk;
    nodePhieuKham *p;
    cout << "\nNhap phieu can them ";
    nhapPhieu(pk);
    p = khoitaoNode_PhieuKham(pk);
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        if (k->pk.vienphi == vienphi_Min(s))
        {
            nodePhieuKham *h = khoitaoNode_PhieuKham(p->pk);
            h->pNext = k->pNext;
            k->pNext = h;
        }
    }
}
void themtruocPhieuMin(stackPhieuKham &s)
{
    phieukham pk;
    cout << "\n Nhap phieu can them ";
    nhapPhieu(pk);
    nodePhieuKham *p = khoitaoNode_PhieuKham(pk);
    nodePhieuKham *g = new nodePhieuKham;
    if (s.pTop == NULL || s.pTop->pk.vienphi == vienphi_Min(s))
    {
        PushPhieuKham(s, p);
    }
    for (nodePhieuKham *k = s.pTop->pNext; k != NULL; k = k->pNext)
    {
        if (k->pk.vienphi == vienphi_Min(s))
        {
            nodePhieuKham *h = khoitaoNode_PhieuKham(p->pk);
            h->pNext = k;
            g->pNext = h;
        }
        g = k;
    }
}

void hoanvi(phieukham &a, phieukham &b)
{
    phieukham tg = a;
    a = b;
    b = tg;
}

void SXtheoVienPhi(stackPhieuKham s)
{
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        for (nodePhieuKham *h = k->pNext; h != NULL; h = h->pNext)
        {
            if (k->pk.vienphi > h->pk.vienphi)
            {
                hoanvi(k->pk, h->pk);
            }
        }
    }
}
void TongTienAllPhieu(stackPhieuKham s)
{
    float tong = 0;
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        tong = tong + k->pk.vienphi;
    }
    cout << "\nTong tien vien phi thu duoc la : " << tong << endl;
}

string tenBenhNhan(string tenKH)
{
    int length = tenKH.length();
    int i;
    for (i = length - 1; i >= 0; i--)
    {
        if (tenKH[i] == ' ')
        {
            break;
        }
    }
    return tenKH.substr(i + 1);
}

void TimkiemtheotenBN(stackPhieuKham s)
{
    cin.ignore();
    cout << "\n Nhap ten khach hang can tim: ";
    string tenbn;
    getline(cin, tenbn);
    bool kt = false;
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        string ten = tenBenhNhan(k->pk.bn.tenBN);
        if (_strcmpi((char *)ten.c_str(), (char *)tenbn.c_str()) == 0)
        {
            hienPhieu(k->pk);
            cout << '\n';
            kt = true;
        }
        cout << endl;
    }
    if (kt == false)
    {
        cout << "\n Khong ton tai benh nhan co ten: " << tenbn << "\n";
    }
}
void TimkiemtheomaBS(stackPhieuKham s)
{
    cout << "\n Moi nhap ma bac si can tim kiem : ";
    int mabs;
    cin >> mabs;
    bool kt = false;
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        if (k->pk.bs.ma == mabs)
        {
            hienPhieu(k->pk);
            kt = true;
            cout << '\n';
        }
    }
    if (kt == false)
    {
        cout << "\nKhong tim thay phieu co ma bac si can tim kiem ! \n";
    }
}
void SuaThongtinphongkham(stackPhieuKham s)
{
    int id;
    bool kt = false;
    cout << "\nMoi nhap ma phieu can sua ";
    cin >> id;
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        if (id == k->pk.maPh)
        {
            stackPK a;
            KhoiTaoStackPK(a);
            cout << "\nNhap lai danh sach phong kham : ";
            nhapDSPhongKham(a);
            k->pk.dspk = a;
            kt = true;
            hienPhieu(k->pk);
            cout << '\n';
        }
    }
    if (kt == false)
        cout << "\nMa phieu nhap vao khong co ! \n";
}
void XoaDauphieu(stackPhieuKham &s)
{
    if (s.pTop == NULL)
    {
        return;
    }
    nodePhieuKham *p = s.pTop;
    s.pTop = s.pTop->pNext;
    delete p;
}
void ChenthemDSPhongKham(stackPhieuKham &s)
{
    int ma;
    cout << "\n Nhap vao ma phieu kham can them phong kham: ";
    cin >> ma;
    for (nodePhieuKham *k = s.pTop; k != NULL; k = k->pNext)
    {
        if (k->pk.maPh == ma)
        {
            int n;
            phongkham x;
            nodePhongKham *p;
            cout << "\n\nNhap so phong kham can them vao :";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                nhapPK(x);
                p = khoiTaoNodePK(x);
                Push(k->pk.dspk, p);
                cout << endl;
            }
        }
    }
}
void GiaiPhongBoNho(stackPhieuKham &s)
{
    nodePhieuKham *k = new nodePhieuKham;
    while (s.pTop != NULL)
    {
        k = s.pTop;
        s.pTop = s.pTop->pNext;
        delete k;
    }
}

void menu(stackPhieuKham &s)
{
    int chon;
    FILE *f;
    do
    {
        cout << "\n\t      _______MENU_______";
        cout << "\n\t 1. Nhap danh sach phieu kham";
        cout << "\n\t 2. Hien danh sach phieu kham";
        cout << "\n\t 3. Luu file danh sach phieu kham";
        cout << "\n\t 4. Doc file va hien danh sach ra man hinh";
        cout << "\n\t 5. Them 1 phieu kham moi vao dau danh sach";
        cout << "\n\t 6. Tim kiem phieu co vien phi nho nhat";
        cout << "\n\t 7. Them phieu vao sau phieu co vien phi nho nhat ";
        cout << "\n\t 8. Them phieu vao truoc phieu co vien phi nho nhat";
        cout << "\n\t 9. Sap xep danh sach tang dan theo vien phi cua phieu";
        cout << "\n\t10. Tong tien thu lai cua cac phieu";
        cout << "\n\t11. Tim kiem phieu theo ten benh nhan duoc nhap tu ban phim";
        cout << "\n\t12. Tim kiem phieu theo ma bac sy tao phieu";
        cout << "\n\t13. Sua thong tin danh sach phong kham : ";
        cout << "\n\t14. Xoa phieu o dau danh sach";
        cout << "\n\t15. Chen them danh sach phong kham";
        cout << "\n\t16. Giai phong bo nho cap phat";
        cout << "\n Moi nhap chuc nang : ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            nhapDSPhieu(s);
            break;
        case 2:
            hienDSPhieu(s);
            break;
        case 3:
            ghiFilePhieuKham(s);
            break;
        case 4:
            docFilePhieuKham(s);
            break;
        case 5:
            them1PhieuKhamvaodauDS(s);
            break;
        case 6:
            timkiemPhieuKham_Min(s);
            break;
        case 7:
            themsauPhieuMin(s);
            break;
        case 8:
            themtruocPhieuMin(s);
            break;
        case 9:
            SXtheoVienPhi(s);
            break;
        case 10:
            TongTienAllPhieu(s);
            break;
        case 11:
            TimkiemtheotenBN(s);
            break;
        case 12:
            TimkiemtheomaBS(s);
            break;
        case 13:
            SuaThongtinphongkham(s);
            break;
        case 14:
            XoaDauphieu(s);
            break;
        case 15:
            ChenthemDSPhongKham(s);
            break;
        case 16:
            GiaiPhongBoNho(s);
            break;
        case 17:
            vienphi_Min(s);
            break;
        default:
            cout << "Moi nhap lai !";
            break;
        }
        system("pause");
        system("cls");
    } while (chon != 0);
}

int main()
{
    stackPhieuKham s;
    khoitaoStackPhieuKham(s);
    menu(s);

    return 0;
}
