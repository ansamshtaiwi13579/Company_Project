################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/user/eclipse-workspace/UnitTest/Test/Ansam.cpp \
/home/user/eclipse-workspace/UnitTest/Test/Foo.cpp 

CPP_DEPS += \
./Test/Ansam.d \
./Test/Foo.d 

OBJS += \
./Test/Ansam.o \
./Test/Foo.o 


# Each subdirectory must supply rules for building sources it contributes
Test/Ansam.o: /home/user/eclipse-workspace/UnitTest/Test/Ansam.cpp Test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Test/Foo.o: /home/user/eclipse-workspace/UnitTest/Test/Foo.cpp Test/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/user/eclipse-workspace/TrainingProject/includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Test

clean-Test:
	-$(RM) ./Test/Ansam.d ./Test/Ansam.o ./Test/Foo.d ./Test/Foo.o

.PHONY: clean-Test

