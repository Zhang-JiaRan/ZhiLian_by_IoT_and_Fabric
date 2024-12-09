import service from "../utils/request";

export function Getdata() {
    return service({
        url: '/tracking',
        method: 'get'
    })
}
