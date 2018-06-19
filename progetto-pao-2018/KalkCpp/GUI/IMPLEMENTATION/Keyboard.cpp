    #include "GUI/HEADER/Keyboard.h"
Keyboard::~Keyboard(){
    delete buttonLayout;
}

void Keyboard::configure(){
    std::vector<QString> multiName =getMultiOperationkeyboard();
    MultiOperationsignalMapper = new QSignalMapper (this) ;

    for(unsigned int i=0; i<multiName.size();i++){
        Operationkeyboard.push_back(new QPushButton(multiName[i]));
        connect (Operationkeyboard.back(), SIGNAL(clicked()), MultiOperationsignalMapper, SLOT(map())) ;
        MultiOperationsignalMapper -> setMapping (Operationkeyboard.back(), i) ;
    }

    connect(MultiOperationsignalMapper, SIGNAL(mapped(int)), this, SIGNAL(multioperation(int))) ;

    std::vector<QString> singleName =getSingleOperationkeyboard();
    SingleOperationsignalMapper = new QSignalMapper (this) ;

    for(unsigned int i=0; i<singleName.size();i++){
        Operationkeyboard.push_back(new QPushButton(singleName[i]));
        connect (Operationkeyboard.back(), SIGNAL(clicked()), SingleOperationsignalMapper, SLOT(map())) ;
        SingleOperationsignalMapper -> setMapping (Operationkeyboard.back(), i) ;
    }

    connect(SingleOperationsignalMapper, SIGNAL(mapped(int)), this, SIGNAL(singleOperation(int)));

    std::vector<QString> extraName =getExtraOperationkeyboard();
    ExtraOperationsignalMapper = new QSignalMapper (this) ;

    for(unsigned int i=0; i<extraName.size();i++){
        Operationkeyboard.push_back(new QPushButton(extraName[i]));
        connect (Operationkeyboard.back(), SIGNAL(clicked()), ExtraOperationsignalMapper, SLOT(map())) ;
        ExtraOperationsignalMapper -> setMapping (Operationkeyboard.back(), i) ;
    }

    connect(ExtraOperationsignalMapper, SIGNAL(mapped(int)), this, SIGNAL(extraoperation(int))) ;

    buttonLayout= new QGridLayout();

    unsigned int row=1;
    for(unsigned int button=0; button<Operationkeyboard.size();button++){
        if(button == row*4){row++;}
        buttonLayout->addWidget(Operationkeyboard[button],row,(button%4)+1);
    }

    buttonLayout->setAlignment(Qt::AlignTop);
    setLayout(buttonLayout);
}
