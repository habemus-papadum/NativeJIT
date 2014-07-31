#pragma once

#include "Temporary/Assert.h"


namespace NativeJIT
{
    class RegisterBase
    {
    protected:
        static unsigned c_sizes[9];
        static char const * c_names[2][4][16];
    };


    template <unsigned SIZE, bool ISFLOAT>
    class Register : public RegisterBase
    {
    public:
        Register()
            : m_id(0)
        {
        }


        Register(unsigned id)
            : m_id(id)
        {
            Assert(id < 16, "Register id cannot exceed 15.");
        }


        template <unsigned SIZE>
        Register(Register<SIZE, false> r)
            : m_id(r.GetId())
        {
        }


        unsigned GetId() const
        {
            return m_id;
        }


        unsigned GetMask() const
        {
            return 1 << m_id;
        }


        char const * GetName() const
        {
            return c_names[ISFLOAT ? 1 : 0][c_sizes[SIZE]][m_id];
        }

    private:
        unsigned m_id;
    };


    extern Register<1, false> al;
    extern Register<1, false> cl;
    extern Register<1, false> dl;
    extern Register<1, false> bl;
    extern Register<1, false> spl;
    extern Register<1, false> bpl;
    extern Register<1, false> sil;
    extern Register<1, false> dil;
    extern Register<1, false> r8b;
    extern Register<1, false> r9b;
    extern Register<1, false> r10b;
    extern Register<1, false> r11b;
    extern Register<1, false> r12b;
    extern Register<1, false> r13b;
    extern Register<1, false> r14b;
    extern Register<1, false> r15b;

    extern Register<2, false> ax;
    extern Register<2, false> cx;
    extern Register<2, false> dx;
    extern Register<2, false> bx;
    extern Register<2, false> sp;
    extern Register<2, false> bp;
    extern Register<2, false> si;
    extern Register<2, false> di;
    extern Register<2, false> r8w;
    extern Register<2, false> r9w;
    extern Register<2, false> r10w;
    extern Register<2, false> r11w;
    extern Register<2, false> r12w;
    extern Register<2, false> r13w;
    extern Register<2, false> r14w;
    extern Register<2, false> r15w;

    extern Register<4, false> eax;
    extern Register<4, false> ecx;
    extern Register<4, false> edx;
    extern Register<4, false> ebx;
    extern Register<4, false> esp;
    extern Register<4, false> ebp;
    extern Register<4, false> esi;
    extern Register<4, false> edi;
    extern Register<4, false> r8d;
    extern Register<4, false> r9d;
    extern Register<4, false> r10d;
    extern Register<4, false> r11d;
    extern Register<4, false> r12d;
    extern Register<4, false> r13d;
    extern Register<4, false> r14d;
    extern Register<4, false> r15d;

    extern Register<8, false> rax;
    extern Register<8, false> rcx;
    extern Register<8, false> rdx;
    extern Register<8, false> rbx;
    extern Register<8, false> rsp;
    extern Register<8, false> rbp;
    extern Register<8, false> rsi;
    extern Register<8, false> rdi;
    extern Register<8, false> r8;
    extern Register<8, false> r9;
    extern Register<8, false> r10;
    extern Register<8, false> r11;
    extern Register<8, false> r12;
    extern Register<8, false> r13;
    extern Register<8, false> r14;
    extern Register<8, false> r15;

    extern Register<8, true> xmm0;
    extern Register<8, true> xmm1;
    extern Register<8, true> xmm2;
    extern Register<8, true> xmm3;
    extern Register<8, true> xmm4;
    extern Register<8, true> xmm5;
    extern Register<8, true> xmm6;
    extern Register<8, true> xmm7;
    extern Register<8, true> xmm8;
    extern Register<8, true> xmm9;
    extern Register<8, true> xmm10;
    extern Register<8, true> xmm11;
    extern Register<8, true> xmm12;
    extern Register<8, true> xmm13;
    extern Register<8, true> xmm14;
    extern Register<8, true> xmm15;
}
