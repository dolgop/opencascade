unit StepWrapperTarget; {$Z4}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Модуль: "w:/CAD/StepWrapperTarget/StepWrapperTarget.pas"
// Delphi обвязка для DLL (.pas)
// Generated from UML model, root element: <<AdapterTarget::Category>> CAD::StepWrapperTarget
//
//
// Все права принадлежат ООО НПП "Гарант-Сервис".
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

interface

uses
	SysConst
	, SysUtils
	, Windows
	, Classes
	, ActiveX
	, StepUnit;

const
	CLibraryVersion: LongWord = 3;
	CLibraryName: PAnsiChar = 'StepWrapperTarget.dll';

type
	// Системные исключения.
	ELoadLibraryError = class (Exception); // используется при загрузке dll; 
	EGetProcAddressError = class (Exception); // используется при вызове операции dll; 
	EStdException = class (Exception); // используется при мапинге неизвестных Sdt исключений; 
	ECorbaException = class (Exception); // используется при мапинге неизвестных CORBA исключений;
	EWrongVersion = class (Exception); // выбрасывается в случае не соответствия версии клиента и dll
	EUnknownFactoryKey = class (Exception); // выбрасывается в случае, если нет ни одного зарегестрированного серванта c заданным ключом для запрашиваемого интерфейса
	
	// exported root factory interface
	IStepWrapperTargetRoot = interface (IInterface) ['{F98207B3-F212-4528-85F0-E56F343C39BF}']
		procedure MakeFaceList (out aRet {: IFaceList}); stdcall;

		procedure MakePointsTable (out aRet {: IPointsTable}); stdcall;

		procedure MakeShapeList (out aRet {: IShapeList}); stdcall;

		procedure MakeStepManager (
			const aFileName: PAnsiChar;
			out aRet {: IStepManager}
		); stdcall; overload;

		procedure MakeTrianglesTable (out aRet {: ITrianglesTable}); stdcall;

	end;

	// DLL wrapper interface
	IStepWrapperTargetDll = interface (IInterface)
		function GetVersion (): LongWord;

		function MakeFaceList () : IFaceList;

		function MakePointsTable () : IPointsTable;

		function MakeShapeList () : IShapeList;

		function MakeStepManager (
			const aFileName: PAnsiChar
		) : IStepManager; overload;

		function MakeTrianglesTable () : ITrianglesTable;


	end;

	// DLL wrapper impl
	TStepWrapperTargetDll = class (TInterfacedObject, IStepWrapperTargetDll)
	private
		f_HModule: HModule;
		f_DllRoot: IStepWrapperTargetRoot;

	private
		procedure DllLoad;
		procedure DllFree;
		procedure RootInit(aClientVersion: LongWord); overload;
		procedure RootInit(aClientVersion: LongWord; const aLocale: PAnsiChar); overload;
		procedure RootDone;
		function GetRoot: IStepWrapperTargetRoot;
	
	public
		constructor Create (aClientVersion: LongWord); reintroduce; overload;
		constructor Create (aClientVersion: LongWord; const aLocale: PAnsiChar); reintroduce; overload;
		destructor Destroy; override;

		class function Make(): IStepWrapperTargetDll; overload;;
		class function Make(const aLocale: PAnsiChar): IStepWrapperTargetDll; overload;;

		function GetVersion: LongWord;
	public
		function MakeFaceList () : IFaceList;

		function MakePointsTable () : IPointsTable;

		function MakeShapeList () : IShapeList;

		function MakeStepManager (
			const aFileName: PAnsiChar
		) : IStepManager; overload;

		function MakeTrianglesTable () : ITrianglesTable;

	end;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
implementation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	function TStepWrapperTargetDll.MakeFaceList () : IFaceList;
	var
		aRes: IFaceList;
	begin
		GetRoot().MakeFaceList(aRes);
		Result := aRes;
	end;

	function TStepWrapperTargetDll.MakePointsTable () : IPointsTable;
	var
		aRes: IPointsTable;
	begin
		GetRoot().MakePointsTable(aRes);
		Result := aRes;
	end;

	function TStepWrapperTargetDll.MakeShapeList () : IShapeList;
	var
		aRes: IShapeList;
	begin
		GetRoot().MakeShapeList(aRes);
		Result := aRes;
	end;

	function TStepWrapperTargetDll.MakeStepManager (
		const aFileName: PAnsiChar
	) : IStepManager;
	var
		aRes: IStepManager;
	begin
		GetRoot().MakeStepManager(aFileName, aRes);
		Result := aRes;
	end;

	function TStepWrapperTargetDll.MakeTrianglesTable () : ITrianglesTable;
	var
		aRes: ITrianglesTable;
	begin
		GetRoot().MakeTrianglesTable(aRes);
		Result := aRes;
	end;



procedure TStepWrapperTargetDll.DllLoad;

	function GetOsDependentCatalog: string;
	begin
		if (Longint (Windows.GetVersion) < 0) then
			Result := ExtractFilePath (ParamStr (0))+'win9X'
		else
			Result := ExtractFilePath (ParamStr (0))+'winNT';
	end;

var
	l_CurrentDir: string;
	l_ErrorMode: UINT;
	l_OsDependentCatalog: string;
begin
	l_ErrorMode := SetErrorMode (SEM_FAILCRITICALERRORS);
	try
		l_CurrentDir := GetCurrentDir;

		l_OsDependentCatalog := GetOsDependentCatalog;
		if SetCurrentDir (l_OsDependentCatalog) then
			try
				f_HModule := LoadLibraryA (CLibraryName);
			finally
				SetCurrentDir (l_CurrentDir);
			end
		else
			f_HModule := LoadLibraryA (PAnsiChar (l_OsDependentCatalog+'\'+CLibraryName));
		
		if (f_HModule = HMODULE (0)) then
		begin
			f_HModule := LoadLibraryA (CLibraryName);
		
			if (f_HModule = HMODULE (0)) then
				raise ELoadLibraryError.Create ('Dynamic library "'+CLibraryName+'" not found');
		end;
	finally
		SetErrorMode (l_ErrorMode);
	end;
end;

procedure TStepWrapperTargetDll.DllFree;
begin
	if (f_HModule <> HMODULE (0)) then
	begin
		try
			FreeLibrary (f_HModule);
		except
		end;
	end;
end;

constructor TStepWrapperTargetDll.Create(aClientVersion: LongWord);
begin
	inherited Create;
	DllLoad;
	RootInit(aClientVersion);
end;

constructor TStepWrapperTargetDll.Create (aClientVersion: LongWord; const aLocale: PAnsiChar);
begin
	inherited Create;
	DllLoad;
	RootInit(aClientVersion, aLocale);
end;

destructor TStepWrapperTargetDll.Destroy;
begin
	f_DllRoot := nil;
	RootDone;
	DllFree;
	inherited;
end;

class function TStepWrapperTargetDll.Make(const aLocale: PAnsiChar): IStepWrapperTargetDll;
begin
	Result := TStepWrapperTargetDll.Create(CLibraryVersion, aLocale);
end;

class function TStepWrapperTargetDll.Make: IStepWrapperTargetDll;
begin
	Result := TStepWrapperTargetDll.Create(CLibraryVersion);
end;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
// plain DLL method's wrappers
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

function TStepWrapperTargetDll.GetVersion: LongWord;
const
	CProcName = '_tie_dll_version@0';
type
	TProcType = function: Integer; stdcall;
var
	l_ProcAddress: Pointer;
begin
	l_ProcAddress := GetProcAddress (f_HModule, PAnsiChar (CProcName));
	if (not Assigned (l_ProcAddress)) then
		raise EGetProcAddressError.Create ('DLL method not found: '+CLibraryName+'.'+CProcName);

	Result := TProcType (l_ProcAddress);
end;

function TStepWrapperTargetDll.GetRoot: IStepWrapperTargetRoot;
const
	CProcName = '_tie_dll_get_root@4';
type
	TProcType = procedure (out aRoot{: IStepWrapperTargetRoot}); stdcall;
var
	l_ProcAddress: Pointer;
begin
	if (not Assigned (f_DllRoot)) then
	begin
		l_ProcAddress := GetProcAddress (f_HModule, PAnsiChar (CProcName));
	
		if (not Assigned (l_ProcAddress)) then
			raise EGetProcAddressError.Create ('DLL method not found: '+CLibraryName+'.'+CProcName);
	
		TProcType (l_ProcAddress)(f_DllRoot);
	end;
	
	Result := f_DllRoot;
end;

procedure TStepWrapperTargetDll.RootInit (aClientVersion: LongWord; const aLocale: PAnsiChar);
const
	CProcName = '_tie_dll_init_with_locale@8';
type
	TProcType = procedure (aClientVersion: LongWord; const aLocale: PAnsiChar); stdcall;
var
	l_ProcAddress: Pointer;
begin
	l_ProcAddress := GetProcAddress (f_HModule, PAnsiChar (CProcName));

	if (not Assigned (l_ProcAddress)) then
		raise EGetProcAddressError.Create ('DLL method not found: '+CLibraryName+'.'+CProcName);

	TProcType (l_ProcAddress) (aClientVersion, aLocale);
end;

procedure TStepWrapperTargetDll.RootInit(aClientVersion: LongWord);
const
	CProcName = '_tie_dll_init@4';
type
	TProcType = procedure (aClientVersion: LongWord); stdcall;
var
	l_ProcAddress: Pointer;
begin
	l_ProcAddress := GetProcAddress (f_HModule, PAnsiChar (CProcName));

	if (not Assigned (l_ProcAddress)) then
		raise EGetProcAddressError.Create ('DLL method not found: '+CLibraryName+'.'+CProcName);

	TProcType (l_ProcAddress) (aClientVersion);
end;

procedure TStepWrapperTargetDll.RootDone;
const
	CProcName = '_tie_dll_done@0';
type
	TProcType = procedure; stdcall;
var
	l_ProcAddress: Pointer;
begin
	if f_HModule <> HMODULE (0) then
	begin
		l_ProcAddress := GetProcAddress (f_HModule, PAnsiChar (CProcName));
	
		if (not Assigned (l_ProcAddress)) then
			raise EGetProcAddressError.Create ('DLL method not found: '+CLibraryName+'.'+CProcName);
			
		TProcType (l_ProcAddress);
	end;
end;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
// exception maping support
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
type
	TExceptionIdMapItem = record
		rId: AnsiString;
		rEClass: ExceptClass;
		rMessage: string;
	end;

resourcestring
	// "Нормальные" текстовые сообщения для исключений, которые "видит" пользователь.
	// (!) Общий формат для имен: строка с именем `S<ИмяИсключения>` соответствует классу с именем `E<ИмяИсключения>`.
	//
	_SBadArgument = 'Аргумент функции выходит за границы допустимых значений';

	_SCantReadFile = 'Ошибка при чтении файла с данными';

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const
	// Карта [map] перекодировки: текстовой строке ставиться в соответствие нужный мета-класс исключения и сообщение.
	//
	cIdToExceptionMapMaxItems = 6; // максимальное количество элементов в таблице

type
	TIdToExceptionMapArray = array [0..cIdToExceptionMapMaxItems - 1] of TExceptionIdMapItem;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

type
	TIdToExceptionMap = class(TObject)
	private
		f_Map: TIdToExceptionMapArray;
	public
		constructor Create;
			reintroduce;
		function ConvertIdToIndex(const aId: PAnsiChar; out aIndex: Longword): Boolean;
		function GetExceptionClass(anIndex: Longword): ExceptClass;
		function CreateException(anIndex: Longword): Exception;
end;

{TIdToExceptionMap}

function TIdToExceptionMap.ConvertIdToIndex(const aId: PAnsiChar; out aIndex: Longword): Boolean;
var
	l_Index: Longword;
begin
	Result := False;
	aIndex := 0;
	for l_Index := Low (f_Map) to High (f_Map) do
		if (StrComp (aId, PAnsiChar (f_Map[l_Index].rId)) = 0) then
		begin
			aIndex := l_Index;
			Result := True;
			
			Break;
		end;
end;

constructor TIdToExceptionMap.Create;
	procedure lp_Init(anIndex: Longword; const aGUID, aMessage: string; const aClass: ExceptClass);
	begin
		with f_Map[anIndex] do
		begin
			rId := aGUID;
			rEClass := aClass;
			rMessage := aMessage;
		end;
	end;

begin
	inherited Create;
	// заполнение f_Map
	
	lp_Init (0, '0000-0000-0000-0000-000000000000', 'dummy exception', EStdException);
	lp_Init (1, '4DDEBC97-3F88-4811-9423-8BDEE07A9C21', 'Выход за границы массива', EListError);
	lp_Init (2, '69708A24-C2D3-4685-8016-7E2FD8A5888C', 'Неправильная версия ДЛЛ', EWrongVersion);
	lp_Init (3, '42540CD0-2B0C-45F2-82DB-0474D2D29867', 'No one servant was registers in factory with a given key', EUnknownFactoryKey);
	lp_Init (5, '9DA313BD-767C-479D-8003-6EA2E11712E6', '_SCantReadFile', ECantReadFile);
	lp_Init (6, '723AEF3B-D02F-4E18-B314-DD71CB48031C', '_SBadArgument', EBadArgument);
end;

function TIdToExceptionMap.CreateException(anIndex: Longword): Exception;
begin
	with f_Map [anIndex] do
		Result := rEClass.Create (rMessage);
end;

function TIdToExceptionMap.GetExceptionClass(anIndex: Longword): ExceptClass;
begin
	Result := f_Map [anIndex].rEClass;
end;

var
	g_ExceptionMap: TIdToExceptionMap = nil;

var
	gExceptClsProc: Pointer;
	gExceptObjProc: Pointer;


function GetExceptionClass (aExceptionRecord: PExceptionRecord): ExceptClass;
type
	TExceptClsProc = function (aExceptionRecord: PExceptionRecord): ExceptClass;
var
	lIndex: Cardinal;
begin
	Result := nil;
	case aExceptionRecord^.ExceptionCode of
		DWORD ($E0040200):
		begin
			if (
				((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0)
				and (aExceptionRecord^.NumberParameters = 0)
			) then
			begin
				Result := EOutOfMemory;
			end;
		end;
		DWORD ($E0040201):
		begin
			if (
				((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0)
				and (aExceptionRecord^.NumberParameters = 1)
				and (aExceptionRecord^.ExceptionInformation [0] <> 0)
			) then
			begin
				Result := EStdException;
			end;
		end;
		DWORD ($E0040202):
		begin
			if (
				((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0)
				and (aExceptionRecord^.NumberParameters = 1)
				and (aExceptionRecord^.ExceptionInformation [0] <> 0)
			) then
			begin
				Result := ECorbaException;
			end;
		end;
		DWORD ($E0040203):
		begin
			if (
				((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0)
				and (aExceptionRecord^.NumberParameters = 1)
				and (aExceptionRecord^.ExceptionInformation [0] <> 0)
				and g_ExceptionMap.ConvertIdToIndex (PAnsiChar (aExceptionRecord^.ExceptionInformation [0]), lIndex)
			) then
				begin
					Result := g_ExceptionMap.GetExceptionClass(lIndex);
				end
			else
				if (
					((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0)
					and (aExceptionRecord^.NumberParameters = 2)
					and (aExceptionRecord^.ExceptionInformation [0] = 0)
					and (aExceptionRecord^.ExceptionInformation [1] <> 0)
				) then
					begin
						Result := g_ExceptionMap.GetExceptionClass(aExceptionRecord^.ExceptionInformation [1]);
					end;
		end;
	end;
	if (
		Result = nil
	) then
	begin
		Result := TExceptClsProc (gExceptClsProc) (aExceptionRecord);
	end;
end;

var
	g_CorbaExceptionMessage : String = '';
	g_StdExceptionMessage : String = '';

function GetExceptionObject (aExceptionRecord: PExceptionRecord): Exception;
type
	TExceptObjProc = function (aExceptionRecord: PExceptionRecord): Exception;
var
	lIndex: Cardinal;
begin
	Result := nil;
	case aExceptionRecord^.ExceptionCode of
		DWORD ($E0040200):
		begin
			if (
				((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0)
				and (aExceptionRecord^.NumberParameters = 0)
			) then
			begin
				// (!) Специальный трюк: это исключение о "нехватке" памяти и оно не может быть создано динамически.
				try
					OutOfMemoryError ();
				except
					on l_Exception: EOutOfMemory do Result := l_Exception;
				end;
			end;
		end;
		DWORD ($E0040201):
		begin
			if ((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0) then
			begin
				if (
					(aExceptionRecord^.NumberParameters = 1)
					and (aExceptionRecord^.ExceptionInformation [0] <> 0)
				) then
				begin
					try
						g_StdExceptionMessage := PAnsiChar (aExceptionRecord^.ExceptionInformation [0]);
						Result := EStdException.Create (g_StdExceptionMessage);
					finally
						try
							CoTaskMemFree (Pointer (aExceptionRecord^.ExceptionInformation [0]));
						finally
							aExceptionRecord^.NumberParameters := 2;
							aExceptionRecord^.ExceptionInformation [0] := 0;
							aExceptionRecord^.ExceptionInformation [1] := DWORD (-1);
						end;
					end;
				end
				else
				begin
					if (
						(aExceptionRecord^.NumberParameters = 2)
						and (aExceptionRecord^.ExceptionInformation [0]  = 0)
						and (aExceptionRecord^.ExceptionInformation [1] = DWORD (-1))
					) then
					begin
						Result := EStdException.Create (g_StdExceptionMessage);
					end;
				end;
			end;
		end;
		DWORD ($E0040202):
		begin
			if ((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0) then
			begin
				if (
					(aExceptionRecord^.NumberParameters = 1)
					and (aExceptionRecord^.ExceptionInformation [0] <> 0)
				) then
				begin
					try
						g_CorbaExceptionMessage := PAnsiChar (aExceptionRecord^.ExceptionInformation [0]);
						Result := ECorbaException.Create (g_CorbaExceptionMessage);
					finally
						try
							CoTaskMemFree (Pointer (aExceptionRecord^.ExceptionInformation [0]));
						finally
							aExceptionRecord^.NumberParameters := 2;
							aExceptionRecord^.ExceptionInformation [0] := 0;
							aExceptionRecord^.ExceptionInformation [1] := DWORD (-1);
						end;
					end;
				end
				else
				begin
					if (
						(aExceptionRecord^.NumberParameters = 2)
						and (aExceptionRecord^.ExceptionInformation [0]  = 0)
						and (aExceptionRecord^.ExceptionInformation [1] = DWORD (-1))
					) then
					begin
						Result := ECorbaException.Create (g_CorbaExceptionMessage);
					end;
				end;
			end;
		end;
		DWORD ($E0040203):
		begin
			if ((aExceptionRecord^.ExceptionFlags and EXCEPTION_NONCONTINUABLE) <> 0) then
			begin
				if (
					(aExceptionRecord^.NumberParameters = 1)
					and (aExceptionRecord^.ExceptionInformation [0] <> 0)
				) then
				begin
					try
						if (
							g_ExceptionMap.ConvertIdToIndex (PAnsiChar (aExceptionRecord^.ExceptionInformation [0]), lIndex)
						) then
						begin
							Result := g_ExceptionMap.CreateException(lIndex);
						end;
					finally
						try
							CoTaskMemFree (Pointer (aExceptionRecord^.ExceptionInformation [0]));
						finally
							aExceptionRecord^.NumberParameters := 2;
							aExceptionRecord^.ExceptionInformation [0] := 0;
							aExceptionRecord^.ExceptionInformation [1] := DWORD (lIndex);
						end;
					end;
				end
				else
				begin
					if (
						(aExceptionRecord^.NumberParameters = 2)
						and (aExceptionRecord^.ExceptionInformation [0]  = 0)
						and (aExceptionRecord^.ExceptionInformation [1] <> 0)
					) then
					begin
						lIndex := Longword (aExceptionRecord^.ExceptionInformation [1]);
						Result := g_ExceptionMap.CreateException(lIndex);
					end;
				end;
			end;
		end;
	end;
	if (Result = nil) then
	begin
		Result := TExceptObjProc (gExceptObjProc) (aExceptionRecord);
	end;
end;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

procedure ExitProc;
begin
	ExceptObjProc := gExceptObjProc;
	ExceptClsProc := gExceptClsProc;
	FreeAndNil(g_ExceptionMap);
end;

procedure InitProc;
begin
	g_ExceptionMap := TIdToExceptionMap.Create;
	gExceptClsProc := ExceptClsProc;
	gExceptObjProc := ExceptObjProc;
	//
	ExceptClsProc := @GetExceptionClass;
	ExceptObjProc := @GetExceptionObject;
end;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

initialization
	InitProc;

finalization
	ExitProc;
	Finalize(g_CorbaExceptionMessage);
	Finalize(g_StdExceptionMessage);

end.