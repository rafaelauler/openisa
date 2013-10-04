; ModuleID = 'calc.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.8.0"

%struct.data = type { i32, i32, i32 }

@main.inicio = private unnamed_addr constant %struct.data { i32 1, i32 1, i32 1 }, align 4
@main.fim = private unnamed_addr constant %struct.data { i32 1, i32 1, i32 1 }, align 4
@.str = private unnamed_addr constant [23 x i8] c"Calculadora de datas.\0A\00", align 1
@.str1 = private unnamed_addr constant [40 x i8] c"Digite a data de in\C3\ADcio (DD/MM/AAAA): \00", align 1
@.str2 = private unnamed_addr constant [9 x i8] c"%d/%d/%d\00", align 1
@.str3 = private unnamed_addr constant [21 x i8] c"\0AEntrada incorreta.\0A\00", align 1
@.str4 = private unnamed_addr constant [35 x i8] c"Digite a data final (DD/MM/AAAA): \00", align 1
@.str5 = private unnamed_addr constant [29 x i8] c"A diferen\C3\A7a \C3\A9 de %d dias.\0A\00", align 1

define i32 @data_para_dias(i64 %d.coerce0, i32 %d.coerce1) nounwind uwtable ssp {
entry:
  %d = alloca %struct.data, align 8
  %coerce = alloca { i64, i32 }, align 8
  %total = alloca i32, align 4
  %0 = getelementptr { i64, i32 }* %coerce, i32 0, i32 0
  store i64 %d.coerce0, i64* %0
  %1 = getelementptr { i64, i32 }* %coerce, i32 0, i32 1
  store i32 %d.coerce1, i32* %1
  %2 = bitcast %struct.data* %d to i8*
  %3 = bitcast { i64, i32 }* %coerce to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %3, i64 12, i32 8, i1 false)
  store i32 0, i32* %total, align 4
  %ano = getelementptr inbounds %struct.data* %d, i32 0, i32 2
  %4 = load i32* %ano, align 4
  %sub = sub nsw i32 %4, 1
  %conv = sitofp i32 %sub to double
  %mul = fmul double %conv, 3.652500e+02
  %conv1 = fptosi double %mul to i32
  store i32 %conv1, i32* %total, align 4
  %mes = getelementptr inbounds %struct.data* %d, i32 0, i32 1
  %5 = load i32* %mes, align 4
  switch i32 %5, label %sw.default [
    i32 12, label %sw.bb
    i32 11, label %sw.bb2
    i32 10, label %sw.bb4
    i32 9, label %sw.bb6
    i32 8, label %sw.bb8
    i32 7, label %sw.bb10
    i32 6, label %sw.bb12
    i32 5, label %sw.bb14
    i32 4, label %sw.bb16
    i32 3, label %sw.bb18
    i32 2, label %sw.bb20
  ]

sw.bb:                                            ; preds = %entry
  %6 = load i32* %total, align 4
  %add = add nsw i32 %6, 30
  store i32 %add, i32* %total, align 4
  br label %sw.bb2

sw.bb2:                                           ; preds = %sw.bb, %entry
  %7 = load i32* %total, align 4
  %add3 = add nsw i32 %7, 31
  store i32 %add3, i32* %total, align 4
  br label %sw.bb4

sw.bb4:                                           ; preds = %sw.bb2, %entry
  %8 = load i32* %total, align 4
  %add5 = add nsw i32 %8, 30
  store i32 %add5, i32* %total, align 4
  br label %sw.bb6

sw.bb6:                                           ; preds = %sw.bb4, %entry
  %9 = load i32* %total, align 4
  %add7 = add nsw i32 %9, 31
  store i32 %add7, i32* %total, align 4
  br label %sw.bb8

sw.bb8:                                           ; preds = %sw.bb6, %entry
  %10 = load i32* %total, align 4
  %add9 = add nsw i32 %10, 31
  store i32 %add9, i32* %total, align 4
  br label %sw.bb10

sw.bb10:                                          ; preds = %sw.bb8, %entry
  %11 = load i32* %total, align 4
  %add11 = add nsw i32 %11, 30
  store i32 %add11, i32* %total, align 4
  br label %sw.bb12

sw.bb12:                                          ; preds = %sw.bb10, %entry
  %12 = load i32* %total, align 4
  %add13 = add nsw i32 %12, 31
  store i32 %add13, i32* %total, align 4
  br label %sw.bb14

sw.bb14:                                          ; preds = %sw.bb12, %entry
  %13 = load i32* %total, align 4
  %add15 = add nsw i32 %13, 30
  store i32 %add15, i32* %total, align 4
  br label %sw.bb16

sw.bb16:                                          ; preds = %sw.bb14, %entry
  %14 = load i32* %total, align 4
  %add17 = add nsw i32 %14, 31
  store i32 %add17, i32* %total, align 4
  br label %sw.bb18

sw.bb18:                                          ; preds = %sw.bb16, %entry
  %15 = load i32* %total, align 4
  %add19 = add nsw i32 %15, 28
  store i32 %add19, i32* %total, align 4
  br label %sw.bb20

sw.bb20:                                          ; preds = %sw.bb18, %entry
  %16 = load i32* %total, align 4
  %add21 = add nsw i32 %16, 31
  store i32 %add21, i32* %total, align 4
  br label %sw.default

sw.default:                                       ; preds = %sw.bb20, %entry
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default
  %ano22 = getelementptr inbounds %struct.data* %d, i32 0, i32 2
  %17 = load i32* %ano22, align 4
  %rem = srem i32 %17, 4
  %cmp = icmp eq i32 %rem, 0
  br i1 %cmp, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %sw.epilog
  %mes24 = getelementptr inbounds %struct.data* %d, i32 0, i32 1
  %18 = load i32* %mes24, align 4
  %cmp25 = icmp sgt i32 %18, 2
  br i1 %cmp25, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  %19 = load i32* %total, align 4
  %add27 = add nsw i32 %19, 1
  store i32 %add27, i32* %total, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %land.lhs.true, %sw.epilog
  %dia = getelementptr inbounds %struct.data* %d, i32 0, i32 0
  %20 = load i32* %dia, align 4
  %21 = load i32* %total, align 4
  %add28 = add nsw i32 %21, %20
  store i32 %add28, i32* %total, align 4
  %22 = load i32* %total, align 4
  ret i32 %22
}

declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) nounwind

define i32 @main() nounwind uwtable ssp {
entry:
  %retval = alloca i32, align 4
  %inicio = alloca %struct.data, align 4
  %fim = alloca %struct.data, align 4
  %fim.coerce = alloca { i64, i32 }
  %inicio.coerce = alloca { i64, i32 }
  store i32 0, i32* %retval
  %0 = bitcast %struct.data* %inicio to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %0, i8* bitcast (%struct.data* @main.inicio to i8*), i64 12, i32 4, i1 false)
  %1 = bitcast %struct.data* %fim to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %1, i8* bitcast (%struct.data* @main.fim to i8*), i64 12, i32 4, i1 false)
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([23 x i8]* @.str, i32 0, i32 0))
  %call1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([40 x i8]* @.str1, i32 0, i32 0))
  %dia = getelementptr inbounds %struct.data* %inicio, i32 0, i32 0
  %mes = getelementptr inbounds %struct.data* %inicio, i32 0, i32 1
  %ano = getelementptr inbounds %struct.data* %inicio, i32 0, i32 2
  %call2 = call i32 (i8*, ...)* @scanf(i8* getelementptr inbounds ([9 x i8]* @.str2, i32 0, i32 0), i32* %dia, i32* %mes, i32* %ano)
  %cmp = icmp ne i32 %call2, 3
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str3, i32 0, i32 0))
  call void @exit(i32 1) noreturn
  unreachable

if.end:                                           ; preds = %entry
  %call4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([35 x i8]* @.str4, i32 0, i32 0))
  %dia5 = getelementptr inbounds %struct.data* %fim, i32 0, i32 0
  %mes6 = getelementptr inbounds %struct.data* %fim, i32 0, i32 1
  %ano7 = getelementptr inbounds %struct.data* %fim, i32 0, i32 2
  %call8 = call i32 (i8*, ...)* @scanf(i8* getelementptr inbounds ([9 x i8]* @.str2, i32 0, i32 0), i32* %dia5, i32* %mes6, i32* %ano7)
  %cmp9 = icmp ne i32 %call8, 3
  br i1 %cmp9, label %if.then10, label %if.end12

if.then10:                                        ; preds = %if.end
  %call11 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str3, i32 0, i32 0))
  call void @exit(i32 1) noreturn
  unreachable

if.end12:                                         ; preds = %if.end
  %2 = bitcast { i64, i32 }* %fim.coerce to i8*
  %3 = bitcast %struct.data* %fim to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %3, i64 12, i32 0, i1 false)
  %4 = getelementptr { i64, i32 }* %fim.coerce, i32 0, i32 0
  %5 = load i64* %4, align 1
  %6 = getelementptr { i64, i32 }* %fim.coerce, i32 0, i32 1
  %7 = load i32* %6, align 1
  %call13 = call i32 @data_para_dias(i64 %5, i32 %7)
  %8 = bitcast { i64, i32 }* %inicio.coerce to i8*
  %9 = bitcast %struct.data* %inicio to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* %9, i64 12, i32 0, i1 false)
  %10 = getelementptr { i64, i32 }* %inicio.coerce, i32 0, i32 0
  %11 = load i64* %10, align 1
  %12 = getelementptr { i64, i32 }* %inicio.coerce, i32 0, i32 1
  %13 = load i32* %12, align 1
  %call14 = call i32 @data_para_dias(i64 %11, i32 %13)
  %sub = sub nsw i32 %call13, %call14
  %call15 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([29 x i8]* @.str5, i32 0, i32 0), i32 %sub)
  call void @exit(i32 0) noreturn
  unreachable

return:                                           ; No predecessors!
  %14 = load i32* %retval
  ret i32 %14
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

declare void @exit(i32) noreturn
