/**
 * File: irgen.h
 * -----------
 *  This file defines a class for LLVM IR Generation.
 *
 *  All LLVM instruction related functions or utilities can be implemented
 *  here. You'll need to customize this class heavily to provide any helpers
 *  or untility as you need.
 */

#ifndef _H_IRGen
#define _H_IRGen

// LLVM headers
#include <vector>
#include <stack>
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/CFG.h"
#include "ast_type.h"

using namespace std;

class IRGenerator {
  public:
    IRGenerator();
    ~IRGenerator();

    llvm::Module   *GetOrCreateModule(const char *moduleID);
    llvm::LLVMContext *GetContext() const { return context; }

    // Add your helper functions here
    llvm::Function *GetFunction() const;
    void      SetFunction(llvm::Function *func);

    llvm::BasicBlock *GetBasicBlock() const;
    void        SetBasicBlock(llvm::BasicBlock *bb);

    llvm::Type *GetIntType() const;
    llvm::Type *GetBoolType() const;
    llvm::Type *GetFloatType() const;
    llvm::Type *GetType(Type *type) const;

    stack<llvm::BasicBlock*> *fbs;
    stack<llvm::BasicBlock*> *cbs;
    stack<llvm::BasicBlock*> *lbs;

  private:
    llvm::LLVMContext *context;
    llvm::Module      *module;

    // track which function or basic block is active
    llvm::Function    *currentFunc;
    llvm::BasicBlock  *currentBB;

    static const char *TargetTriple;
    static const char *TargetLayout;
};

#endif

