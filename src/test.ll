declare void @createCanvas(double, double)
declare void @background(double)
declare void @stroke(double)
declare void @fill(double)
declare void @ellipse(double, double, double, double)
declare void @line(double, double, double, double)
declare void @point(double, double)
declare double @sqrt(double)
declare double @log10(double)
declare double @sin(double)
declare double @cos(double)
define i32 @square(i32 %x_param){
%x_param = alloca i32
ret i32 %x3
}
define i32 @add(i32 %y_param, i32 %v_param){
%y_param = alloca i32
%v_param = alloca i32
ret i32 %x7
}
define i32 @main(){
%x8 = alloca i32
%x9 = alloca i32
%x10 = add i32 0, 0
%x11 = alloca i32
store i32 %x10, i32* %x11
%x12 = load i32, i32* %x9
%x13 = load i32, i32* %x11
%x12 = load i32, i32* %x9
%x15 = alloca i32
store i32 %x14, i32* %x15
store i32 %x11, i32* %x9
br i1 %x21 label %l0, label %l1
l0:
%x31 = load i32, i32* %x9
%x38 = load i32, i32* %x8
%x40 = call i32 @add(i32 %x31, i32 %x38)
store i32 %x40, i32* %x39
%x41 = load i32, i32* %x8
%x42 = load i32, i32* %x39
%x41 = load i32, i32* %x8
%x44 = alloca i32
store i32 %x43, i32* %x44
store i32 %x39, i32* %x8
%x22 = load i32, i32* %x9
%x23 = add i32 %x22, 1
store i32 %x23, i32* %x9
%x16 = add i32 0, 1000
%x17 = alloca i32
store i32 %x16, i32* %x17
%x18 = load i32, i32* %x9
%x19 = load i32, i32* %x17
%x20 = icmp slt i32 %x18, %x19
%x21 = alloca i32
store i32 %x20, i32* %x21
br i1 %x21 label %l0, label %l1
l1:
ret i32 %x8
}

