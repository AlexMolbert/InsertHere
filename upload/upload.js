'use strict';

angular.module('webApp.upload', ['ngRoute', 'firebase'])

.config(['$routeProvider', function($routeProvider){
	$routeProvider.when('/upload', {
		templateUrl: 'upload/upload.html',
		controller: 'UploadCtrl'
	});
}])

.controller('UploadCtrl', ['$scope', '$firebaseArray', '$location', 'CommonProp', function($scope, $firebaseArray, $location, CommonProp){

}]);