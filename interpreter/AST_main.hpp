#pragma once

#include <iostream>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>

class Type;

// Global LLVM variables related to the LLVM suite.
static llvm::LLVMContext TheContext;
static llvm::IRBuilder<> Builder(TheContext);
static std::unique_ptr<llvm::Module> TheModule;
static std::unique_ptr<llvm::legacy::FunctionPassManager> TheFPM;

static llvm::Type *i32 = llvm::Type::getInt32Ty(TheContext);
static llvm::Type *i8 = llvm::Type::getInt8Ty(TheContext);
static llvm::Type *i1 = llvm::Type::getInt1Ty(TheContext);
static llvm::Type *proc = llvm::Type::getVoidTy(TheContext);

static inline llvm::ConstantFP* fp(float n) {
    return llvm::ConstantFP::get(TheContext, llvm::APFloat(n));
  }

static inline llvm::Constant *c32(int n)
{
	return llvm::ConstantInt::get(i32, n);
}

static inline llvm::Constant *c8(unsigned char b)
{
	return llvm::ConstantInt::get(i8, b);
}

static inline llvm::Constant *c1(int n)
{
	return llvm::ConstantInt::get(i1,n);
}


class AST {
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;
  virtual void sem() {}
  virtual void sem(Type*) {}
  virtual void sem(bool b) {}
  virtual llvm::Value* compile() {
    return nullptr;
  }

  void llvm_compile_and_dump() {
    // Initialize the module and the optimization passes.
    TheModule = llvm::make_unique<llvm::Module>("program", TheContext);
    TheFPM = llvm::make_unique<llvm::legacy::FunctionPassManager>(TheModule.get());
    TheFPM->add(llvm::createPromoteMemoryToRegisterPass());
    TheFPM->add(llvm::createInstructionCombiningPass());
    TheFPM->add(llvm::createReassociatePass());
    TheFPM->add(llvm::createGVNPass());
    TheFPM->add(llvm::createCFGSimplificationPass());
    TheFPM->doInitialization();
    // Define and initialize global symbols.
    // @vars = global [26 x i32] zeroinitializer, align 16
    /*ArrayType *vars_type = ArrayType::get(i32, 26);
    TheVars = new GlobalVariable(
        *TheModule, vars_type, false, GlobalValue::PrivateLinkage,
        ConstantAggregateZero::get(vars_type), "vars");
    TheVars->setAlignment(16);*/
    // @nl = private constant [2 x i8] c"\0A\00", align 1
    /*ArrayType *nl_type = ArrayType::get(i8, 2);
    TheNL = new GlobalVariable(
        *TheModule, nl_type, true, GlobalValue::PrivateLinkage,
        ConstantArray::get(nl_type,
          std::vector<Constant *> { c8('\n'), c8('\0') }
        ), "nl");
    TheNL->setAlignment(1);*/
    // declare void @writeInteger(i64)
    /*llvm::FunctionType *writeInteger_type =
      llvm::FunctionType::get(llvm::Type::getVoidTy(TheContext),
                        std::vector<llvm::Type *> { i64 }, false);
    TheWriteInteger =
      llvm::Function::Create(writeInteger_type, llvm::Function::ExternalLinkage,
                       "writeInteger", TheModule.get());
    // declare void @writeString(i8*)
    llvm::FunctionType *writeString_type =
      llvm::FunctionType::get(llvm::Type::getVoidTy(TheContext),
                        std::vector<llvm::Type *> { llvm::PointerType::get(i8, 0) }, false);
    TheWriteString =
      llvm::Function::Create(writeString_type, llvm::Function::ExternalLinkage,
                       "writeString", TheModule.get());
    // Define and start the main function.
    llvm::Function *main =
      llvm::cast<llvm::Function>(TheModule->getOrInsertFunction("main", i32));*/
    /*llvm::BasicBlock *BB = llvm::BasicBlock::Create(TheContext, "entry", main);
    Builder.SetInsertPoint(BB);
    // Emit the program code.
    compile();
    Builder.CreateRet(c32(0));
    // Verify the IR.
    bool bad = llvm::verifyModule(*TheModule, &llvm::errs());
    if (bad) {
      std::cerr << "The IR is bad!" << std::endl;
      std::exit(1);
    }
    TheFPM->run(*main);
    // Print out the IR.
    TheModule->print(llvm::outs(), nullptr);*/
  }
};


inline std::ostream& operator<< (std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}

