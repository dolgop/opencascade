unit StepUnit; {$Z4}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Библиотека "StepWrapper"
// Модуль: "w:/CAD/StepWrapper/StepUnit.pas"
// Delphi интерфейсы для адаптера (.pas)
// Generated from UML model, root element: <<Interfaces::Category>> CAD::StepWrapper::Step
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

interface

uses
	SysUtils
	;

type

IPointsTable = interface;
{ - предварительное описание IPointsTable. }

ITrianglesTable = interface;
{ - предварительное описание ITrianglesTable. }

ILocation = interface;
{ - предварительное описание ILocation. }

IFace = interface;
{ - предварительное описание IFace. }

INameWrapper = interface;
{ - предварительное описание INameWrapper. }

IFaceList = interface;
{ - предварительное описание IFaceList. }

IShape = interface;
{ - предварительное описание IShape. }

IShapeList = interface;
{ - предварительное описание IShapeList. }

IStepManager = interface;
{ - предварительное описание IStepManager. }


// Ошибка при чтении файла с данными
ECantReadFile = class (Exception);

// Аргумент функции выходит за границы допустимых значений
EBadArgument = class (Exception);

PPoint = ^TPoint;
TPoint = packed record
	rX: Single;
	rY: Single;
	rZ: Single;
end;

PTriangleInfo = ^TTriangleInfo;
TTriangleInfo = packed record
	rIndex1: Cardinal;
	rIndex2: Cardinal;
	rIndex3: Cardinal;
end;

// - COMPOUND: A group of any of the shapes below.
// - COMPSOLID: A set of solids connected by their
// faces. This expands the notions of WIRE and SHELL to solids.
// - SOLID: A part of 3D space bounded by shells.
// - SHELL: A set of faces connected by some of the
// edges of their wire boundaries. A shell can be open or closed.
// - FACE: Part of a plane (in 2D geometry) or a surface
// (in 3D geometry) bounded by a closed wire. Its
// geometry is constrained (trimmed) by contours.
// - WIRE: A sequence of edges connected by their
// vertices. It can be open or closed depending on
// whether the edges are linked or not.
// - EDGE: A single dimensional shape corresponding
// to a curve, and bound by a vertex at each extremity.
// - VERTEX: A zero-dimensional shape corresponding to a point in geometry.
PShapeType = ^TShapeType;
TShapeType = (
	ST_COMPOUND
	, ST_COMPSOLID
	, ST_SOLID
	, ST_SHELL
	, ST_FACE
	, ST_WIRE
	, ST_EDGE
	, ST_VERTEX
	, ST_SHAPE
);

IPointsTable = interface(IInterface)
['{E9B9F2F6-BD5D-45E2-940E-9FA60A3BC812}']
    function  pm_GetCount: Integer; stdcall;
    procedure pm_SetCount(aValue: Integer); stdcall;
      { - методы для доступа к свойству Count. }
    procedure Clear; stdcall;
      {* очистить список. }
    procedure Delete(anIndex: Integer); stdcall;
      {* удаляет элемент по индексу Index. }
    property Count: Integer
      read pm_GetCount
      write pm_SetCount;
       {* число элементов в хранилище. }
  // property methods
    procedure  pm_GetItem(anIndex: Integer; out aRet: TPoint); stdcall;

    procedure pm_SetItem(anIndex: Integer; const anItem: TPoint); stdcall;
      {-}
  // public methods
    function  Add(const anItem: TPoint): Integer; stdcall;
      {* - добавляет элемент Item в конец. }
    procedure Insert(anIndex: Integer; const anItem: TPoint); stdcall;
      {* - вставляет элемент Item по индексу Index. }
end;//IPointsTable

ITrianglesTable = interface(IInterface)
['{61DF71CB-2C82-4AEC-897D-70832480E8E0}']
    function  pm_GetCount: Integer; stdcall;
    procedure pm_SetCount(aValue: Integer); stdcall;
      { - методы для доступа к свойству Count. }
    procedure Clear; stdcall;
      {* очистить список. }
    procedure Delete(anIndex: Integer); stdcall;
      {* удаляет элемент по индексу Index. }
    property Count: Integer
      read pm_GetCount
      write pm_SetCount;
       {* число элементов в хранилище. }
  // property methods
    procedure  pm_GetItem(anIndex: Integer; out aRet: TTriangleInfo); stdcall;

    procedure pm_SetItem(anIndex: Integer; const anItem: TTriangleInfo); stdcall;
      {-}
  // public methods
    function  Add(const anItem: TTriangleInfo): Integer; stdcall;
      {* - добавляет элемент Item в конец. }
    procedure Insert(anIndex: Integer; const anItem: TTriangleInfo); stdcall;
      {* - вставляет элемент Item по индексу Index. }
end;//ITrianglesTable

// получить матрицу трансформации поверхности
ILocation = interface (IInterface) ['{5FA812D9-DAEF-417B-B476-867D823D62FC}']
	function DontUseMe: Pointer;
	function GetIndex (
		aRow: Cardinal;
		aColumn: Cardinal
	): Single; stdcall; // can raise EBadArgument
end;

// Сетка на фигуре
IFace = interface (IInterface) ['{1DABC3CF-750E-49B8-8111-08EE3DD773D8}']
	function DontUseMe: Pointer;
	procedure GetLocation (
		out aRet {: ILocation}
	); stdcall;

	procedure GetNormalsTable (
		out aRet {: IPointsTable}
	); stdcall;

	procedure GetPointsTable (
		out aRet {: IPointsTable}
	); stdcall;

	procedure GetTrianglesTable (
		out aRet {: ITrianglesTable}
	); stdcall;

	procedure GetWirePoints (
		aIndex: Cardinal;
		out aRet {: IPointsTable}
	); stdcall;

	// Количество wires для данного face
	function GetWiresCount (): Cardinal; stdcall;
end;

INameWrapper = interface (IInterface) ['{CF85555E-0F2C-4310-8D1C-65C6DA73A3AE}']
	function DontUseMe: Pointer;
	function GetName (): PAnsiChar; stdcall;
end;

IFaceList = interface(IInterface)
['{0D7A3091-18B8-4D93-A60E-CC8A93BADE84}']
    function  pm_GetCount: Integer; stdcall;
    procedure pm_SetCount(aValue: Integer); stdcall;
      { - методы для доступа к свойству Count. }
    procedure Clear; stdcall;
      {* очистить список. }
    procedure Delete(anIndex: Integer); stdcall;
      {* удаляет элемент по индексу Index. }
    property Count: Integer
      read pm_GetCount
      write pm_SetCount;
       {* число элементов в хранилище. }
  // property methods
    procedure  pm_GetItem(anIndex: Integer; out aRet: IFace); stdcall;

    procedure pm_SetItem(anIndex: Integer; const anItem: IFace); stdcall;
      {-}
  // public methods
    function  Add(const anItem: IFace): Integer; stdcall;
      {* - добавляет элемент Item в конец. }
    procedure Insert(anIndex: Integer; const anItem: IFace); stdcall;
      {* - вставляет элемент Item по индексу Index. }
end;//IFaceList

// фигура
IShape = interface (IInterface) ['{6AC53346-3C79-459B-B798-98AD1078C8B5}']
	function DontUseMe: Pointer;
	// параметр, задающий точность триангуляции
	function GetDeflection (): Double; stdcall;
	procedure SetDeflection (aDeflection: Double); stdcall;

	// возвращает список поверхностей для всех фигур, входящих в заданную (включая её саму)
	procedure GetAllFaceList (
		out aRet {: IFaceList}
	); stdcall;

	// Возвращает список дочерних фигур для заданной
	procedure GetChildrenList (
		out aRet {: IShapeList}
	); stdcall;

	// возвращает список поверхностей для заданной фигуры
	procedure GetFaceList (
		out aRet {: IFaceList}
	); stdcall;

	// координаты текущей фигуры
	procedure GetLocation (
		out aRet {: ILocation}
	); stdcall;

	// возвращает топологический объект, являющийся отцом заданного
	procedure GetOriginalShape (
		out aRet {: IShape}
	); stdcall;

	// вернуть тип топологического объекта
	function GetType (): TShapeType; stdcall;

	// замкнута ли поверхность
	function IsClosed (): Bytebool; stdcall;

	// сравнивает 2 фигуры на равенство
	function IsEqual (
		const aToCompare: IShape
	): Bytebool; stdcall;

	// имя конкретной фигуры
	procedure GetLocalName (out aRet {: INameWrapper}); stdcall;

	// имя топологической фигуры, являющейся базовой для данной
	procedure GetMainName (out aRet {: INameWrapper}); stdcall;
end;

IShapeList = interface(IInterface)
['{3CD99711-71E6-4C6F-8A8D-3EBAF6D0830C}']
    function  pm_GetCount: Integer; stdcall;
    procedure pm_SetCount(aValue: Integer); stdcall;
      { - методы для доступа к свойству Count. }
    procedure Clear; stdcall;
      {* очистить список. }
    procedure Delete(anIndex: Integer); stdcall;
      {* удаляет элемент по индексу Index. }
    property Count: Integer
      read pm_GetCount
      write pm_SetCount;
       {* число элементов в хранилище. }
  // property methods
    procedure  pm_GetItem(anIndex: Integer; out aRet: IShape); stdcall;

    procedure pm_SetItem(anIndex: Integer; const anItem: IShape); stdcall;
      {-}
  // public methods
    function  Add(const anItem: IShape): Integer; stdcall;
      {* - добавляет элемент Item в конец. }
    procedure Insert(anIndex: Integer; const anItem: IShape); stdcall;
      {* - вставляет элемент Item по индексу Index. }
end;//IShapeList

// Основной интерфейс для работы с данными, полученными из step-файла
IStepManager = interface (IInterface) ['{BD33C6C6-3616-4411-AB73-DFF8D5AAC731}']
	function DontUseMe: Pointer;
	// Возвращает заданную фигуру верхнего уровня
	procedure GetRoot (
		aIndex: Cardinal;
		out aRet {: IShape}
	); stdcall; // can raise EBadArgument

	// Количество фигур верхнего уровня (не являющихся частью других фигур)
	function GetRootsCount (): Cardinal; stdcall;
end;

implementation
end.