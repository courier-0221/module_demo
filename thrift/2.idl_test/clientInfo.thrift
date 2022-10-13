namespace cpp vnmp

enum ClientType {
    DOM_MANAGER,
    DOM_SERVICE
}

enum RegistResult {
    SUCCESS,
    NAME_EXISTED,
    INVALIE_PARA,
}

struct ClientInfo {
    1: string name,
    2: string realIP,
    3: string vpnIP,
    4: ClientType type,
    5: optional string description,
}

service Regist {
    RegistResult registClient(1:ClientInfo clientInfo),
    bool heartbeat(1:string name, 2:ClientType type)
}