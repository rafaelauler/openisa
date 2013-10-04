#!/bin/bash -x

for arq in $(find .); do newarq=$(sed -e 's/Mips/Oi/g;' <<<$arq); mv $arq $newarq; done

for arq in $(find .); do sed -i '' 's/mips/oi/g;' $arq; done
for arq in $(find .); do sed -i '' 's/Mips/Oi/g;' $arq; done
for arq in $(find .); do sed -i '' 's/MIPS/OI/g;' $arq; done


# rename back intrinsics and relocations
for arq in $(find . -name "*td"); do sed -i '' "s/int\_oi/int\_mips/g" $arq; done
for arq in $(find . -name "*cpp"); do sed -i '' "s/VK\_Oi/VK\_Mips/g" $arq; done
for arq in $(find . -name "*cpp"); do sed -i '' "s/SK\_Oi/SK\_Mips/g" $arq; done
for arq in $(find . -name "*h"); do sed -i '' "s/SK\_Oi/SK\_Mips/g" $arq; done
for arq in $(find .); do sed -i '' "s/STO\_OI\_MICROOI/STO\_MIPS\_MICROMIPS/g" $arq; done
for arq in $(find . -name "*cpp"); do sed -i '' "s/R\_OI/R\_MIPS/g" $arq; done
for arq in $(find . -name "*cpp"); do sed -i '' "s/EM\_OI/EM\_MIPS/g" $arq; done
for arq in $(find . -name "*cpp"); do sed -i '' "s/EF\_OI/EF\_MIPS/g" $arq; done
for arq in $(find .); do sed -i '' "s/EF\_MIPS\_MICROOI/EF\_MIPS\_MICROMIPS/g" $arq; done
sed -i '' "s/Triple::oi/Triple::mips/g" MCTargetDesc/OiMCAsmInfo.cpp
sed -i '' "s/Triple::oi/Triple::mips/g" TargetInfo/OiTargetInfo.cpp
sed -i '' "s/Intrinsic::oi/Intrinsic::mips/g" OiSEISelLowering.cpp
for arq in $(find .); do sed -i '' "s/SHT\_OI/SHT\_MIPS/g" $arq; done
for arq in $(find .); do sed -i '' "s/SHF\_OI/SHF\_MIPS/g" $arq; done


echo Now you need to register correctly in TargetInfo/OiTargetInfo.cpp. Use an example.
