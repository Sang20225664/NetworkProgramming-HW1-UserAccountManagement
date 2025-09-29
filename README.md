# NetworkProgramming-HW1-UserAccountManagement
# IT4062 - Homework 1

## 📌 Bài toán

Quản lý tài khoản người dùng với các chức năng:

1. Log in
2. Post message
3. Logout
4. Exit

Người dùng được lưu trong file `account.txt` với cấu trúc:

```
username status
```

* `status = 1`: tài khoản hoạt động.
* `status = 0`: tài khoản bị khóa (banned).

Chương trình cần ghi log mọi hoạt động vào file `log_<MSSV>.txt` theo định dạng:

```
[dd/mm/yyyy hh:mm:ss] $ <menu-option> $ <user-input> $ <result>
```

Trong đó `<result>` là `+OK` nếu thành công, `-ERR` nếu thất bại.

---

## 📂 Cấu trúc project

```
HW1/
 ├── account.txt          # File chứa thông tin tài khoản
 ├── main.cpp             # Chương trình chính (menu)
 ├── user/
 │   ├── user.cpp         # Định nghĩa struct User và hàm loadAccounts
 │   └── user.h
 ├── logger/
 │   ├── logger.cpp       # Hàm writeLog để ghi log
 │   └── logger.h
 ├── functions/
 │   ├── functions.cpp    # Các chức năng: login, post, logout, exit
 │   └── functions.h
 ├── Makefile             # Script biên dịch
 └── log_<MSSV>.txt       # File log được sinh ra khi chạy chương trình
```

---

## ⚙️ Cách build và chạy

```bash
make        # Biên dịch chương trình
./main      # Chạy chương trình
make clean  # Dọn file thực thi và file .o
```

---

## 📝 Cách sử dụng

* **Log in**: nhập username để đăng nhập.

  * Nếu user tồn tại và active (status=1) → đăng nhập thành công.
  * Nếu user không tồn tại → thông báo "Account does not exist".
  * Nếu user bị khóa (status=0) → thông báo "Account is banned".
  * Nếu đã đăng nhập rồi → thông báo "You have already logged in".
* **Post message**: nhập nội dung, chỉ thành công nếu đã đăng nhập.
* **Logout**: chỉ thành công nếu đang đăng nhập.
* **Exit**: thoát chương trình.

---

## 🧪 Ví dụ kiểm thử

Với file `account.txt`:

```
tungbt 1
levn 0
hungbt 1
```

Kịch bản:

```
1 Username: tung   -> Account does not exist
1 Username: levn   -> Account is banned
2 Post message: Hi -> You have not logged in.
1 Username: tungbt -> Hello tungbt
2 Post message: Hi -> Successful post
3                  -> Successful log out
```

File log sẽ ghi:

```
[21/09/2025 14:42:24] $ 1 $ tung $ -ERR
[21/09/2025 14:46:24] $ 1 $ levn $ -ERR
[21/09/2025 14:48:12] $ 2 $ Hi $ -ERR
[21/09/2025 14:49:12] $ 1 $ tungbt $ +OK
[21/09/2025 14:50:01] $ 2 $ Hi $ +OK
[21/09/2025 14:51:57] $ 3 $ $ +OK
```

---

