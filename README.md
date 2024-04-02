# GAME DINO RUNNING
• Nguyễn Hoàng Điệp – 22026534

• K67-CN16-UET

• Bài tập: INT2215 1 - Lập Trình Nâng Cao
# Giới thiệu
• Dino running được lấy ý tưởng từ tựa game Dinosaur running, là một tựa game đã vô cùng nổi tiếng và gắn liền với thế hệ 10X trên toàn thế giới.

• Với Dino running, mất mạng trên Chrome sẽ không còn là điều nhàm chán mà trở nên rất thú vị nhờ vào khả năng giết thời gian mang tính giải trí cao.

• Điểm cộng rất lớn của Dino running là nó không chỉ được nâng cấp về tính năng, độ khó của game mà còn vô cùng mãn nhãn với phần đồ hoạ sinh động, đẹp mắt.

• Được viết bằng ngôn ngữ C++, kết hợp sử dụng thư viện SDL2
# Lý do chọn game
• Đối với phiên bản Chrome cũ, thao tác còn chưa được cải thiện, hình ảnh không được mượt mà, cộng thêm không phải người dùng nào cũng 'dễ dàng' mất kết nối Internet để truy cập vào game.

• Dino running là phiên bản đã được cải tiến hơn rất nhiều, đặc biệt phù hợp với hầu như mọi lứa tuổi ( trên 3), vừa giúp tăng khả năng phản xạ và tránh nhàm chán khi người dùng không có phương tiện kết nối với Internet.

• Đây là dự án đầu tay rất phù hợp với sinh viên bởi tính đơn giản, hữu dụng và không quá phức tạp đòi hỏi các kỹ năng quá cao cấp.

• Với độ phổ biến của của phiên bản gốc thì dino running không khó để tiếp cận với người chơi.

• Một phần vì đây chính là một tựa game mình yêu thích từ rất lâu.
# Luật chơi
• Người chơi sử dụng các phím mũi tên và xuống để giúp chú khủng long nhảy lên và cúi xuống tránh các chương ngại vật để đi được quãng đường xa nhất.

• Điểm số sẽ tỉ lệ thuận với thời gian mà người chơi chơi được khi chưa va phải vật cản ( tức là càng chơi lâu thì điểm càng cao ) , điểm chơi cao nhất sẽ được hệ thống ghi nhận lại
# Mô tả tính năng
<img width="629" alt="237912837-de669a34-b7ac-4e01-a5c1-d1ae83585b4b" src="https://github.com/hoangdiep271024/dinosaur/assets/144908726/f2f5de08-ae69-4e45-b925-1ae701e669f1"></br>
• Click vào Play để bắt đầu game

• Click vào Quit hoặc biểu tượng X ở góc phải màn hình để thoát game

• Click vào biểu tượng dấu chấm hỏi để tìm hiểu rõ hơn về cách chơi.

![237913196-089db1c1-a517-4af0-8f76-6345b6acee50](https://github.com/hoangdiep271024/dinosaur/assets/144908726/63acba66-372e-461d-b6cc-04d907fc562a)</br>
• Trong quá trình chơi thì người chơi, có việc bận thì bấm biểu tượng dừng để dừng lại

• Click vào biểu tượng âm thanh để bật hoặc tắt âm thanh
</br>
![237913325-dcaa2b4d-5f6a-4d3f-b60d-3e2263dc3af7](https://github.com/hoangdiep271024/dinosaur/assets/144908726/251bd883-7162-4c18-9ac9-34fe6bf4d445)
</br>
• Click vào continue để tiếp tục chơi

• Click 2 lần vào Menu để chơi lại giao diện ban đầu để bắt đầu lại game mới

</br>
![237913441-f7cbdc4c-254f-4fb5-a831-116b78bb0311](https://github.com/hoangdiep271024/dinosaur/assets/144908726/bbdb1617-bd4d-4486-8626-02b0f62012c4)

</br>
• Khi người chơi va chạm với vật cản mà điểm nhỏ hơn hoặc bằng 200 thì sẽ load ra giao diện như trên </br>
![237913511-81423869-b408-488f-b5b1-586fb9bc58bc](https://github.com/hoangdiep271024/dinosaur/assets/144908726/c7ba28a3-61c6-4bd7-b9f8-7836a53ca888)

</br>
• Khi người chơi va chạm với vật cản mà điểm lớn hơn 200 và nhỏ hơn hoặc bằng 450 thì sẽ load ra giao diện như trên </br>
![237914757-062f6f52-f522-4e1a-858e-e3f45bfd5de5](https://github.com/hoangdiep271024/dinosaur/assets/144908726/19ad975d-ca0d-4ce2-8dc1-4b0d97ac76c7)

</br>
• Khi người chơi va chạm với vật cản mà điểm lớn hơn hoặc bằng 450 thì sẽ load ra giao diện như trên

• Vật cản chính là 1 cây xương rồng cute:)) nhưng khi điểm lớn hơn 150 sẽ xuất hiện thêm 1 con chim vô cùng thật trân.

• Nếu chơi đủ lâu thì người chơi sẽ được trải qua 3 lần thay đổi cảnh.

• Càng chơi lâu thì tốc độ của vật cản sẽ càng tăng làm cho độ khó của game khó dần.
# Hướng dẫn cài đặt
• Cài đặt sẵn VS code hoặc Visual studio…..

• Tải các thư viện hỗ trợ SDL: SDL2, SDL2_mixer, SDL2_image, SDL2_ttf.

• Tải source code về giải nén và click zô diep.exe và chơi game.
# RESOURCE
https://lazyfoo.net/tutorials/SDL/
https://github.com/tiendat-aops/dinosaur
# TỔNG KẾT
Lợi ích:

• Đã có thể tự tay làm ra một game đầu tay mà mình yêu thích từ rất lâu.

• Trau dồi thêm được nhiều kỹ năng năng mềm với github, edit ảnh, ……

• Cải thiện và trau dồi được thêm rất nhiều kĩ năng về lập trình

• Rèn luyện được thêm về khả năng tự học

• Biết cách sử dụng SDL2 với những thao tác cơ bản như(load ảnh, sự kiện chuột, render chữ lên màn hình bằng ttf,..).

Hạn chế: • Thuật toán về toạ độ cho các chướng ngại vật còn có phần chưa hợp lý

• Chưa đa dạng về các loại vật cản

• Các tính năng trong game còn thiếu phần đa dạng.

• Còn nhiều thiếu sót trong việc trình bày code .

Định hướng phát triển:

• Thêm tính năng chọn nhân vật, thêm vật cản để làm cho game trở nên hấp dẫn hơn

• Có thể thêm những vật dụng trên đường để nhân vật trang bị thêm (giống tựa game Dino Swords)

• Tạo ra tính năng thêm mạng cho nhân vật….

Và sau cùng em xin gửi lời cảm ơn đến các thầy vì đã giúp em tạo ra được một sản phẩm đầu tay của em, tuy chưa hoàn hảo nhưng cũng là thành quả sau một quá trình dài cố gắng. Thank for reading.







